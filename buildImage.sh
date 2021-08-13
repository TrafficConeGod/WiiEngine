test ! -f Image.iso && mksdcard 50M Image.iso
sudo mount -o defaults,umask=000 Image.iso Media/SDCard
cp -r Data Media/SDCard
sudo umount Media/SDCard