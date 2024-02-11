for ((i=1; i<=10; i++)); do
  echo "Тест $i: "
  python randomayzer.py > file.txt
  python main.py < file.txt > temp.txt
  ./decimal < file.txt | python main2.py >> temp.txt
  python sravnenie.py < temp.txt
done
