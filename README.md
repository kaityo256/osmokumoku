# OS自作もくもく ログ

## Windows WSL2 (Ubuntu)での実行方法

### qemuのインストール。

```sh
sudo hwclock -s # WSLは時間がずれることが多いので修正
sudo apt update
sudo apt upgrade
sudo apt install qemu qemu-system qemu-utils
```

`qemu-system-x86_64`のバージョンが4.2.1ならOK。

```sh
$ qemu-system-x86_64 --version
QEMU emulator version 4.2.1 (Debian 1:4.2-3ubuntu6.16)
Copyright (c) 2003-2019 Fabrice Bellard and the QEMU Project developers
```

### リポジトリのクローンと実行

```sh
mkdir github
cd github
git clone https://github.com/uchan-nos/mikanos-build.git osbook
git clone https://github.com/kaityo256/osmokumoku.git
```

`osmokumoku`ディレクトリの中のchap01の`mkimg.sh`と`run.sh`を実行する。

```sh
cd osmokumoku
cd chap01
source mkimg.sh
source run.sh
```

QEMUが起動し、Hello, world!が表示されるはず。

## Macでの環境構築(準備中)

## [作業ログ](log.md)

## ライセンス

CC-BY
