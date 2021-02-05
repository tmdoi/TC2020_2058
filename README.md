# TC2020_2058

## つくばチャレンジ2020の参加記録

- チーム名：大阪府大高専・つくばチャレンジチーム
- 代表者：土井智晴　大阪府立大学工業高等専門学校　教授

## 目標

- マイコンを多用したシステムでロボットを構築する
- 地磁気センサに基づき特定方位に向かて自律走行する
- RTK-GPSを利用して自律走行を行う

## 成果

- Arduino 1台、マイクロビット 3台で屋外移動ロボットを構成した。
- マイクロビットの地磁気センサを用いて特定方位に向かって自律走行することができた。
- RTK-GPSで位置情報を計測した。
  - ラズパイでRTK-GPSデータを取得するpythonプログラムを作成したが、緯度経度データに基づく自律走行はできなかった。

## 資料

- ロボット駆動系のハードウェア
  - [Sabertooth dual 25A motor driver](https://www.dimensionengineering.com/products/sabertooth2x25)
  - 特徴
    - 電源電圧　DC 6-30V
    - 2channel: 25A continuous, 50A peak per channel
    - シリアル通信でモータの速度制御が可能

- ロボット駆動系のソフトウェア
  - [限定Qiita：モータドライバ駆動用プログラム等のまとめ](https://qiita.com/tmdoi/private/fd4f11deb5544f232aad)
  - ドライバに対して駆動用マイクロビットからシリアル通信により送られるキャラクタ1文字のデータに基づき、左右のモータの正転、逆転、停止を制御している。
