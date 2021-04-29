//	stationaryorbit/core/objectholder
//	Copyright 2020 zawa-ch.
//	GPLv3 (or later) license
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//	See the GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program.
//	If not, see <http://www.gnu.org/licenses/>.
//
#ifndef __stationaryorbit_core_objectholder__
#define __stationaryorbit_core_objectholder__
#include <memory>
#include <functional>
#include "nullreference.hpp"
namespace zawa_ch::StationaryOrbit
{
	///	オブジェクトの所有権にかかわらず、オブジェクトへの参照を保持します。
	///	@note
	///	@a ObjectHolder は渡された参照の種類によって参照を保持する、または内部にオブジェクトをコピー・ムーブするを決定する参照ハンドラです。
	///	参照・ポインタを渡された場合のオブジェクトの生存期間は参照先オブジェクトのものとなり、依然タングリング参照が発生する可能性があることに注意してください。
	template<class T, class = std::enable_if_t<!std::is_const_v<T>>>
	class ObjectHolder final
	{
		friend class ObjectHolderHelper;
	public:
		typedef T ValueType;
		typedef T* Pointer;
		typedef T& Reference;
		typedef const T& ConstReference;
		typedef T&& ValueMove;
		typedef void (*DeleteHandler)(T*);
	private:
		Pointer _ptr;
		DeleteHandler _deleter;
	public:
		///	規定の @a ObjectHolder を構築します。
		constexpr ObjectHolder() : _ptr(nullptr), _deleter(non_delete) {}
		///	どのオブジェクトも参照しない @a ObjectHolder を構築します。
		constexpr ObjectHolder(std::nullptr_t) : _ptr(nullptr), _deleter(non_delete) {}
		///	指定されたオブジェクトを参照する @a ObjectHolder を構築します。
		constexpr ObjectHolder(Reference object) : _ptr(&object), _deleter(non_delete) {}
		///	指定されたオブジェクトを保持する @a ObjectHolder を構築します。
		ObjectHolder(ValueMove object) : _ptr(create_ptr(std::move(object))), _deleter(default_delete) {}
		///	指定されたオブジェクトからムーブ構築します。
		ObjectHolder(ObjectHolder<T>&& other) = default;
	private:
		constexpr ObjectHolder(Pointer ptr, DeleteHandler deleter) : _ptr(ptr), _deleter(deleter) {}
	public:
		~ObjectHolder() { clear(); }
		ObjectHolder<T>& operator=(std::nullptr_t)
		{
			clear();
			return *this;
		}
		ObjectHolder<T>& operator=(ObjectHolder<T>&& other) = default;

		///	このオブジェクトが値を持っているかを取得します。
		[[nodiscard]] constexpr bool has_value() const noexcept { return _ptr != nullptr; }

		///	このオブジェクトが参照するオブジェクトを所有しているかを取得します。
		[[nodiscard]] constexpr bool is_owner() const noexcept { return _deleter != non_delete; }

		///	このオブジェクトが保持している参照の参照先を取得します。
		[[nodiscard]] constexpr Reference value() { if (!has_value()) { throw NullReferenceException("内容が null の ObjectHolder を間接参照しようとしました。"); } return *_ptr; }
		[[nodiscard]] constexpr Reference operator*() { return value(); }

		///	このオブジェクトが保持している参照の参照先を取得します。
		[[nodiscard]] constexpr ConstReference value() const { if (!has_value()) { throw NullReferenceException("内容が null の ObjectHolder を間接参照しようとしました。"); } return *_ptr; }
		[[nodiscard]] constexpr ConstReference operator*() const { return value(); }

		constexpr Pointer operator->() { if (!has_value()) { throw NullReferenceException("内容が null の ObjectHolder を間接参照しようとしました。"); } return _ptr; }
		constexpr const Pointer operator->() const { if (!has_value()) { throw NullReferenceException("内容が null の ObjectHolder を間接参照しようとしました。"); } return _ptr; }

		///	このオブジェクトの内容を削除します。
		void clear() noexcept { _deleter(_ptr); _deleter = non_delete; _ptr = nullptr; }

		///	他のオブジェクトとの等価比較を行います。
		///	@param	other
		///	比較対象となるオブジェクト。
		[[nodiscard]] constexpr bool equals(const ObjectHolder<T>& other) const noexcept { return (_ptr == other._ptr); }
		[[nodiscard]] constexpr bool operator==(const ObjectHolder<T>& other) const noexcept { return equals(other); }
		[[nodiscard]] constexpr bool operator!=(const ObjectHolder<T>& other) const noexcept { return !equals(other); }
	private:
		static Pointer create_ptr(ValueMove obj) { return new T(std::move(obj)); }
		static void default_delete(Pointer ptr) noexcept { delete ptr; }
		constexpr static void non_delete(Pointer ptr) noexcept { return; }
	};
	///	オブジェクトの所有権にかかわらず、オブジェクトへの参照を保持します。
	///	@note
	///	@a ObjectHolder は渡された参照の種類によって参照を保持する、または内部にオブジェクトをコピー・ムーブするを決定する参照ハンドラです。
	///	参照・ポインタを渡された場合のオブジェクトの生存期間は参照先オブジェクトのものとなり、依然タングリング参照が発生する可能性があることに注意してください。
	template<class T>
	class ObjectHolder<T, std::enable_if_t<(!std::is_const_v<T>) && std::is_copy_constructible_v<T>>> final
	{
		friend class ObjectHolderHelper;
	public:
		typedef T ValueType;
		typedef T* Pointer;
		typedef T& Reference;
		typedef const T& ConstReference;
		typedef T&& ValueMove;
		typedef void (*DeleteHandler)(T*);
	private:
		Pointer _ptr;
		DeleteHandler _deleter;
	public:
		///	規定の @a ObjectHolder を構築します。
		constexpr ObjectHolder() : _ptr(nullptr), _deleter(non_delete) {}
		///	どのオブジェクトも参照しない @a ObjectHolder を構築します。
		constexpr ObjectHolder(std::nullptr_t) : _ptr(nullptr), _deleter(non_delete) {}
		///	指定されたオブジェクトを参照する @a ObjectHolder を構築します。
		constexpr ObjectHolder(Reference object) : _ptr(&object), _deleter(non_delete) {}
		///	指定されたオブジェクトを複製する @a ObjectHolder を構築します。
		ObjectHolder(ConstReference object) : _ptr(create_ptr(object)), _deleter(default_delete) {}
		///	指定されたオブジェクトを保持する @a ObjectHolder を構築します。
		ObjectHolder(ValueMove object) : _ptr(create_ptr(object)), _deleter(default_delete) {}
		///	指定されたオブジェクトからコピー構築します。
		ObjectHolder(const ObjectHolder<T>& other) : _ptr((other.has_value())?((other.is_owner())?(create_ptr(other.value())):(other._ptr)):(nullptr)), _deleter((other.has_value() && other.is_owner())?(default_delete):(non_delete)) {}
		///	指定されたオブジェクトからムーブ構築します。
		ObjectHolder(ObjectHolder<T>&& other) = default;
	private:
		constexpr ObjectHolder(Pointer ptr, DeleteHandler deleter) : _ptr(ptr), _deleter(deleter) {}
	public:
		~ObjectHolder() { clear(); }
		ObjectHolder<T>& operator=(std::nullptr_t)
		{
			clear();
			return *this;
		}
		ObjectHolder<T>& operator=(const ObjectHolder<T>& other)
		{
			clear();
			_ptr = ((other.has_value())?((other.is_owner())?(create_ptr(other.value())):(other._ptr)):(nullptr));
			_deleter = ((other.has_value() && other.is_owner())?(default_delete):(non_delete));
			return *this;
		}
		ObjectHolder<T>& operator=(ObjectHolder<T>&& other) = default;

		///	このオブジェクトが値を持っているかを取得します。
		[[nodiscard]] constexpr bool has_value() const noexcept { return _ptr != nullptr; }

		///	このオブジェクトが参照するオブジェクトを所有しているかを取得します。
		[[nodiscard]] constexpr bool is_owner() const noexcept { return _deleter != non_delete; }

		///	このオブジェクトが保持している参照の参照先を取得します。
		[[nodiscard]] constexpr Reference value() { if (!has_value()) { throw NullReferenceException("内容が null の ObjectHolder を間接参照しようとしました。"); } return *_ptr; }
		[[nodiscard]] constexpr Reference operator*() { return value(); }

		///	このオブジェクトが保持している参照の参照先を取得します。
		[[nodiscard]] constexpr ConstReference value() const { if (!has_value()) { throw NullReferenceException("内容が null の ObjectHolder を間接参照しようとしました。"); } return *_ptr; }
		[[nodiscard]] constexpr ConstReference operator*() const { return value(); }

		constexpr Pointer operator->() { if (!has_value()) { throw NullReferenceException("内容が null の ObjectHolder を間接参照しようとしました。"); } return _ptr; }
		constexpr const Pointer operator->() const { if (!has_value()) { throw NullReferenceException("内容が null の ObjectHolder を間接参照しようとしました。"); } return _ptr; }

		///	このオブジェクトが保持している参照の参照先を取得します。取得できない場合は指定された値を使用します。
		[[nodiscard]] constexpr T value_or(ConstReference or_value) const noexcept { if (has_value()) { return *_ptr; } else { return or_value; } }

		///	このオブジェクトの内容を削除します。
		void clear() noexcept { _deleter(_ptr); _deleter = non_delete; _ptr = nullptr; }

		///	他のオブジェクトとの等価比較を行います。
		///	@param	other
		///	比較対象となるオブジェクト。
		[[nodiscard]] constexpr bool equals(const ObjectHolder<T>& other) const noexcept { return (_ptr == other._ptr); }
		[[nodiscard]] constexpr bool operator==(const ObjectHolder<T>& other) const noexcept { return equals(other); }
		[[nodiscard]] constexpr bool operator!=(const ObjectHolder<T>& other) const noexcept { return !equals(other); }
	private:
		static Pointer create_ptr(ConstReference obj) { return new T(obj); }
		static Pointer create_ptr(ValueMove obj) { return new T(std::move(obj)); }
		static void default_delete(Pointer ptr) noexcept { delete ptr; }
		static void non_delete(Pointer ptr) noexcept { return; }
	};
}
#endif // __stationaryorbit_core_objectholder__
