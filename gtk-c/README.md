Dependencies needed for gtk4

```bash
sudo apt install libwayland-dev \
	wayland-protocols \
	libgdk-pixbuf2.0-dev \
	libglib2.0-dev \
	libgstreamer-plugins-bad1.0-dev \
	libxinerama-dev \
	libxdamage-dev \
	libxcursor-dev \
	libxi-dev \
	libxrandr-dev \
	libxkbcommon-dev

pip3 install meson
```

Then to build gtk..

```bash
git clone git@gitlab.gnome.org:GNOME/gtk.git
```

```bash
# From root of gtk source
meson setup --prefix /opt/gtk build
cd build
ninja
ninja install
```

Tried to build wayland-protocols from source, version was too old, needed 1.21
https://github.com/wayland-project/wayland-protocols/tree/1.21

Steps to build it are similar

```bash
meson setup build
cd build
ninja
ninja install
```

Unfortunately I think I need a new version of pango as well

Missing a "g_module_open_full" symbol as well? Not sure what that's supposed to come from

This is the command I used to generate the ridiculous list of arguments in build.sh

```bash
PKG_CONFIG_PATH=/opt/gtk/lib/x86_64-linux-gnu/pkgconfig pkg-config --cflags --libs gtk4
```
