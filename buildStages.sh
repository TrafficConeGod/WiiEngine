cd Stages
for file in *
do
    name="${file%.*}"
    scc ../SCCTypes.csv "$file" ../Data/Stages/"$name".stg
done