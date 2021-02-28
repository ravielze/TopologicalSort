# Topological Sort

Topological Sort merupakan metode decrease and conquer varian decrease by a variable size. Persoalan direduksi menjadi sub-persoalan sebesar jumlah simpul yang derajat masuknya 0. Graf yang digunakan pada permasalahan ini adalah graf jenis directed acyclic.

## Deskripsi Singkat

Pertama, Semua simpul akan dihitung derajat masuknya. Lalu, semua simpul yang berderajat 0 akan dihilangkan dan dimasukkan ke semester i. Dilakukan penghapusan busur keluar dari simpul yang memiliki derajat 0. Terakhir, dilakukan pengulangan setelah penghapusan simpul berderajat 0 dan busur keluarnya dan dimasukkan ke semester (i+1). Hal ini terus dilakukan sampai graf tidak memiliki simpul.

## Requirement Program

- Compiler G++ >= 9.2.0

## Cara Menggunakan Program

### Compile

Lakukan ```cd src && g++ main.cpp ./reader/reader.cpp ./graph/graph.cpp ./common/RomanNumber.cpp```

### Windows
Lakukan ```topoSort.exe <nama file> <jumlah kuliah per baris>```
Contoh: ```topoSort.exe ../test/test1.txt 5```
<nama file>: tempat ke file bersangkutan
<jumlah kuliah per baris>: penulisan per baris, untuk kerapian

### Linux
Sama seperti windows hanya saja ganti topoSort.exe menjadi ./topoSort
Contoh: ```./topoSort ../test/test1.txt 5```

## Identitas Pembuat
Program ini dibuat oleh [Steven Nataniel](https://github.com/ravielze) untuk menuntaskan tugas kecil 2 dari mata kuliah IF2211 Strategi Algoritma