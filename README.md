# OS自作もくもく ログ

## Windows WSL2 (Ubuntu)での実行方法

### qemuのインストール

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

以下、`osmokumoku`ディレクトリの`chap01_wsl`で作業。

```sh
cd osmokumoku
cd chap01_wsl
```

イメージの作成手順。

```sh
qemu-img create -f raw disk.img 200M
mkfs.fat -n 'MIKAN OS' -s 2 -f 2 -R 32 -F 32 disk.img
mkdir -p mnt
sudo mount -o loop disk.img mnt
sudo mkdir -p mnt/EFI/BOOT
sudo cp BOOTX64.EFI mnt/EFI/BOOT/BOOTX64.EFI
sudo umount mnt
```

QEMUで実行

```sh
qemu-system-x86_64 -drive if=pflash,file=$HOME/github/osbook/devenv/OVMF_CODE.fd -drive if=pflash,file=$HOME/github/osbook/devenv/OVMF_VARS.fd -hda disk.img
```

以上をまとめて以下のようにシェルスクリプトを実行しても良い。

```sh
source mkimg.sh
source run.sh
```

QEMUが起動し、Hello, world!が表示されるはず。

![fig](fig/hello_world.png)

## Macでの環境構築

### バイナリエディタ

Macのバイナリエディタはとりあえず[Hex Fiend](https://hexfiend.com/)が良いと思われる。ViewsのLine Number FormatをHexadecimalにして、幅も調整すると本との対応をつけやすい。

![Hex Fiend](fig/hexfiend.png)

### リポジトリのクローン

```sh
mkdir github
cd github
git clone https://github.com/uchan-nos/mikanos-build.git osbook
git clone https://github.com/kaityo256/osmokumoku.git
```

以下、`chap01_mac`で作業。

```sh
cd osmokumoku
cd chap01_mac
```

### qemuとdosfstoolsのインストール

```sh
brew install qemu dosfstools
```

### ディスクイメージの作成

```sh
qemu-img create -f raw disk.img 200M
/usr/local/Cellar/dosfstools/4.2/sbin/mkfs.fat -n 'MIKAN OS' -s 2 -f 2 -R 32 -F 32 disk.img       
```

### ディスクへの書き込み

```sh
open disk.img
```

Finderで「MIKAN OS」がマウントされたのを確認してから、

```sh
mkdir -p /Volumes/MIKAN\ OS/EFI/BOOT
cp BOOTX64.EFI /Volumes/MIKAN\ OS/EFI/BOOT
```

その後、Finderの「MIKAN OS」の右側にあるイジェクトボタン(unmount)を押す。

![finder](fig/finder.png)

コマンドラインからのunmountでは正しく書き込みがなされないので注意。

### QEMUの起動

```sh
qemu-system-x86_64 -drive if=pflash,file=$HOME/github/osbook/devenv/OVMF_CODE.fd -drive if=pflash,file=$HOME/github/osbook/devenv/OVMF_VARS.fd -hda disk.img
```

QEMUが起動し、Hello, world!が表示されるはず。

![fig](fig/hello_world_mac.png)

### シェルスクリプト

以上の作業をまとめて、

```sh
source mkimg.sh
```

手作業でのunmount。

```sh
source run.sh
```

で行ける。

## [作業ログ](log.md)

## ライセンス

CC-BY
