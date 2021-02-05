# TC2020_2058

## つくばチャレンジ2020の参加記録

- チーム名：大阪府大高専・つくばチャレンジチーム
- 代表者：土井智晴　大阪府立大学工業高等専門学校　教授

## 目標

- マイコンを多用したシステムで自律ロボットを構築する
- 地磁気センサに基づき特定方位に向かて自律走行する
- RTK-GPSを利用して自律走行を行う

## 成果

- Arduino 1台、マイクロビット 3台で屋外移動ロボットを構成した。
- マイクロビットの地磁気センサを用いて特定方位に向かって自律走行することができた。
- RTK-GPSで位置情報を計測した。
  - ラズパイでRTK-GPSデータを取得するpythonプログラムを作成したが、緯度経度データに基づく自律走行はできなかった。

## 外部発表実績

- [2020/09/12（土） 13:00〜 つくばチャレンジ2020第1回LT大会](https://tsukubachallenge.connpass.com/event/187976/)
   - [講演資料](https://speakerdeck.com/tmdoi/fu-da-gao-zhuan-timuzi-ji-shao-jie-tukubatiyarenzi2020di-1hui-ltda-hui)
- [2020/11/28(土) 12:45〜 つくばチャレンジ2020第2回LT大会](https://tsukubachallenge.connpass.com/event/195912/)
   - [講演資料](https://speakerdeck.com/tmdoi/fu-da-gao-zhuan-timufalsexian-zhuang-tukubatiyarenzi2020di-2hui-ltda-hui)
- [計測自動制御学会 SI2020講演会 ]()
  - 講演資料 マックHDクラッシュのため消失（涙）
  - [講演概要](https://github.com/tmdoi/TC2020_2058/blob/main/papers/SI2020.pdf)

- [第14回つくばチャレンジ2020シンポジウム](https://tsukubachallenge.connpass.com/event/200361/)
  - [講演概要](https://github.com/tmdoi/TC2020_2058/blob/main/papers/TS2020.pdf)

## ロボットの構成に関する情報

### 駆動系
- ロボット駆動系のハードウェア
  - [Sabertooth dual 25A motor driver](https://www.dimensionengineering.com/products/sabertooth2x25)
  - 特徴
    - 電源電圧　DC 6-30V
    - 2channel: 25A continuous, 50A peak per channel
    - シリアル通信でモータの速度制御が可能

- ロボット駆動系のソフトウェア　使用マイコン：ArduinoUNO
  - [限定Qiita：モータドライバ駆動用プログラム等のまとめ](https://qiita.com/tmdoi/private/fd4f11deb5544f232aad)
  - モータを駆動するプログラムはArduino Unoで作成
    - ドライバに対して駆動用マイクロビットからシリアル通信により送られるキャラクタ1文字のデータに基づき、左右のモータの正転、逆転、停止を制御している。

### 制御用装置とそのプログラム
- 駆動部制御のための無線受信機的な装置
　- 駆動用micro:bit
    - 駆動系のArduinoUNOとコントローラ（手動操縦用micro:bitおよび自律制御用micro:bit）と通信する
    - [駆動用micro:bitのプログラム](https://makecode.microbit.org/50438-16375-80770-39312)
- 手動コントローラ
  - 手動操縦用micro:bit
    - [GameZip64をコントローラとした](https://kitronik.co.uk/products/5626-game-zip-64-for-the-bbc-microbit)
    - 上部に挿入するマイクロビットを手動操縦用micro:bitと呼ぶ。
    - 手動操縦用micro:bitのA、Bボタンで手動制御と自律制御を切り替える。
    - [手動制御用micro:bitのプログラム](https://makecode.microbit.org/_FPLCkw83P6mj)
- 自律コントローラ（２種類）
  - 自律コントローラとして２種類作成した
  - 一つは、北を目指して走行するプログラム。もう一つは、東西南北を選択して走行するプログラム。
  - 自律走行のコマンドをコンパスからのセンシング値によって走行コマンドを生成し、駆動用micro:bitに送信する。
    - [東西南北版の自律走行用micro:bitのプログラム](https://makecode.microbit.org/_UipfcibLgTzs)
    - 北限定の自律走行用micro:bitのプログラムは上と重複するので掲載していない

### RTK-GPS
 - [SoftBank ichimill](https://www.softbank.jp/biz/iot/service/ichimill/)を使用した
   - 数センチの誤差でデータ取得ができた
   - Raspberry PiとUSBケーブル接続して、pythonコードでGPS-Dataを取得できることは確認した

### URG
 - URGをArduinoに接続してデータ取得しようと試みた
 - シリアル通信でデータを受信できたがデコードを自力で書くことを断念した。
    - [Qiita:Ardinoでデコードの格闘記録](https://qiita.com/tmdoi/items/92dc81577ec2cba148e6)     

# 謝辞
- 機器提供を頂いた北陽電機株式会社様、ありがとうございます。
- ichimillに関して技術提供をいただきましたSoftBank ALES様、ありがとうございます。 
