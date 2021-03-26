# stationaryorbit.core

[stationaryorbit](https://github.com/zawa-ch/stationaryorbit) » core

![Lisence](https://img.shields.io/github/license/zawa-ch/stationaryorbit.core)
![Lines of code](https://img.shields.io/tokei/lines/github/zawa-ch/stationaryorbit.core)

簡単なことを簡単に行うためのライブラリ

## 概要

stationaryorbit.core は stationaryorbit の基本となるライブラリです。  
このソースのビルドにはC++17に準拠したコンパイラが必要になります。  

## このライブラリでできること

- 値の範囲型(`Range`)
  (c++20にて標準ライブラリに組み込まれる予定の`std::range`と同程度の機能)
- ハンドラー型(`Delegate`)
- プロパティ(`Property`)
- 平面上の点・大きさ・および矩形(`Point2D`/`Rect2DSize`/`Rectangle2D`)
- true/falseのいずれでもない状態を持つbool値(`Logic`)
- 二次元ベクトル(`Vector2D`)
- 0..1間の値を表す型(`Proportion`)
- データのビット単位でのアクセス(`BitReference`)
- ビットマスク型(`BitMask`)

## ライセンス

このライブラリは、GNU一般公衆ライセンス v3.0(GPLv3)、またはそれ以降のライセンスで提供されます。  
ライセンスに関する詳細は[LISENCE](./LICENSE)ファイル、または[ライセンス - GNUプロジェクト](http://www.gnu.org/licenses/)のページをご確認ください。  

## 注意: 開発中のリポジトリ

現在このリポジトリは開発中です。そのため、オブジェクトの名前および配置が大きく変化する可能性があります。  
同様の理由で、ドキュメント等も不十分な可能性があります。  
