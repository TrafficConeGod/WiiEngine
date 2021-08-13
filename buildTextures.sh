cd Textures
for file in *
do
    name="${file%.*}"
    gxtexconv -i "$file" -o ../Data/Textures/"$name".tpl
    rm ../Data/Textures/"$name".h
done