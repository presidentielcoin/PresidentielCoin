
Debian
====================
This directory contains files used to package presidentielcoind/presidentielcoin-qt
for Debian-based Linux systems. If you compile presidentielcoind/presidentielcoin-qt yourself, there are some useful files here.

## presidentielcoin: URI support ##


presidentielcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install presidentielcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your presidentielcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/presidentielcoin128.png` to `/usr/share/pixmaps`

presidentielcoin-qt.protocol (KDE)

