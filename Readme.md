# 🎬 Sistem Pemesanan Tiket Bioskop

Program ini merupakan aplikasi berbasis C++ yang digunakan untuk melakukan pemesanan tiket bioskop melalui terminal (console). Pengguna dapat melihat daftar film, melakukan navigasi halaman film, memilih kursi, memesan tiket, melihat antrian pembelian, serta melihat histori transaksi.

Project ini dibuat untuk menerapkan konsep:

* Struktur Data
* Algoritma
* Object Oriented Programming (OOP)
* Pointer
* Modular Programming

---

# 📖 Latar Belakang

Dalam sebuah bioskop, proses pemesanan tiket harus dilakukan secara cepat, teratur, dan mudah digunakan oleh pelanggan. Selain itu, sistem juga harus mampu mengelola data film, kursi, transaksi, dan antrian pembelian secara efisien.

Oleh karena itu, dibuatlah program pemesanan tiket bioskop berbasis terminal menggunakan bahasa C++ dengan menerapkan berbagai konsep struktur data yang dipelajari dalam perkuliahan.

Melalui project ini, mahasiswa dapat memahami bagaimana struktur data digunakan dalam implementasi sistem nyata.

---

# 🎯 Tujuan Project

Tujuan dibuatnya program ini adalah:

1. Membuat sistem pemesanan tiket bioskop sederhana berbasis C++.
2. Menerapkan konsep struktur data dalam studi kasus nyata.
3. Melatih penggunaan Object Oriented Programming (OOP).
4. Memahami implementasi Linked List, Queue, Stack, dan Pointer.
5. Membuat kode yang modular dan mudah dikembangkan.

---

# 🧠 Konsep Program

Program ini menggunakan beberapa konsep utama:

| Konsep      | Fungsi                              |
| ----------- | ----------------------------------- |
| Struct      | Menyimpan data film dan kursi       |
| Class       | Mengatur sistem bioskop             |
| Linked List | Menyimpan daftar film               |
| Queue       | Menyimpan antrian pembelian tiket   |
| Stack       | Menyimpan histori transaksi         |
| Pointer     | Menghubungkan node linked list      |
| Array 2D    | Menyimpan data kursi setiap film    |
| Pagination  | Menampilkan film 5 data per halaman |
| Sorting     | Mengurutkan jadwal film             |

---

# ⚙️ Fitur Program

## ✅ Daftar Film dengan Pagination

Film ditampilkan menggunakan sistem pagination.

Setiap halaman menampilkan maksimal 5 film.

Navigasi yang tersedia:

```txt
N = Next Page
P = Previous Page
Q = Kembali
```

Informasi yang ditampilkan:

* Kode Film
* Judul Film
* Harga Tiket
* Rating Umur
* Jadwal Tayang

---

## ✅ Pemesanan Tiket

Pengguna dapat:

* Memilih film berdasarkan kode
* Memasukkan jumlah tiket
* Memilih kursi secara manual
* Melakukan pembayaran

---

## ✅ Validasi Film R18+

Sistem akan memeriksa usia pengguna sebelum pemesanan.

Contoh:

```txt
PERINGATAN!
Film ini khusus usia 18+
```

---

## ✅ Diskon Otomatis

Jika jumlah tiket yang dibeli lebih dari 5 tiket, maka sistem memberikan diskon sebesar 10%.

---

## ✅ Kursi Per Film

Setiap film memiliki data kursi masing-masing.

Representasi kursi:

```txt
O = Kosong
X = Terisi
```

Kursi disimpan menggunakan array dua dimensi:

```cpp
bool kursi[5][5];
```

---

## ✅ Queue Pembelian

Setiap transaksi pembelian akan masuk ke dalam antrian pembelian tiket.

Konsep yang digunakan:

```txt
FIFO (First In First Out)
```

---

## ✅ Histori Transaksi

Semua transaksi akan disimpan ke dalam histori transaksi menggunakan stack.

Konsep yang digunakan:

```txt
LIFO (Last In First Out)
```

---

## ✅ Sorting Jadwal Film

Film dapat diurutkan berdasarkan jadwal tayang menggunakan algoritma Bubble Sort pada Linked List.

---

# 🧩 Struktur Folder Project

```txt
uap-sda/
│
├── main.cpp
│
├── include/
│   ├── bioskop.h
│   ├── film.h
│   ├── kursi.h
│   ├── queue.h
│   ├── stack.h
│   └── utils.h
│
├── src/
│   ├── bioskop.cpp
│   ├── film.cpp
│   ├── kursi.cpp
│   ├── queue.cpp
│   ├── stack.cpp
│   └── utils.cpp
│
└── README.md
```

---

# 🔄 Alur Program

```txt
Mulai Program
      ↓
Tampilkan Menu
      ↓
Lihat Daftar Film
      ↓
Pilih Film
      ↓
Validasi Umur
      ↓
Pilih Kursi
      ↓
Hitung Total Harga
      ↓
Cek Diskon
      ↓
Simpan ke Queue
      ↓
Simpan ke Stack
      ↓
Cetak Tiket
      ↓
Selesai
```

---

# 🧮 Algoritma yang Digunakan

## 1. Linked List

Digunakan untuk menyimpan daftar film secara dinamis.

Keuntungan:

* Mudah ditambah
* Fleksibel
* Tidak memerlukan ukuran tetap

---

## 2. Pagination

Digunakan untuk menampilkan data film sebanyak 5 film per halaman.

Tujuan:

* Mempermudah navigasi
* Tampilan lebih rapi
* Mudah digunakan saat jumlah film bertambah

---

## 3. Queue

Digunakan untuk menyimpan antrian pembelian tiket.

Konsep:

```txt
FIFO (First In First Out)
```

---

## 4. Stack

Digunakan untuk menyimpan histori transaksi.

Konsep:

```txt
LIFO (Last In First Out)
```

---

## 5. Array 2D

Digunakan untuk menyimpan data kursi setiap film.

```cpp
bool kursi[5][5];
```

---

## 6. Bubble Sort

Digunakan untuk mengurutkan jadwal film berdasarkan waktu tayang.

---

# 💻 Cara Compile Program

## Linux / MacOS

```bash
g++ main.cpp src/*.cpp -o bioskop
```

## Windows (MinGW)

```bash
g++ main.cpp src/*.cpp -o bioskop.exe
```

---

# ▶️ Menjalankan Program

## Linux / MacOS

```bash
./bioskop
```

## Windows

```bash
bioskop.exe
```

---

# 🖥️ Contoh Menu Program

```txt
==============================
BIOSKOP APP
==============================

1. Daftar Film (Pagination)
2. Pesan Tiket
3. Lihat Kursi Film
4. Sorting Film
5. Queue Pembelian
6. Histori
0. Keluar
```

---

# 🎟️ Contoh Tiket

```txt
========== TIKET ==========

Nama      : Rehan
Film      : Avengers Endgame
Jadwal    : 13:00
Jumlah    : 2
Total     : Rp 100000

===========================
```

---

# 👥 Pembagian Tugas Kelompok

| No | Anggota   | Tugas                                                                            |
| -- | --------- | -------------------------------------------------------------------------------- |
| 1  | Ananda Raihan Alfarizi | Analisis kebutuhan sistem, perancangan alur program (flowchart), implementasi modul Utility (utils.h & utils.cpp), implementasi Queue Pembelian (queue.h & queue.cpp), implementasi Stack Histori (stack.h & stack.cpp), serta pengujian fitur Queue dan Stack.        |
| 2  | Luna Adelia | Implementasi modul Film (film.h & film.cpp), termasuk Struct Film, Linked List data film, pencarian film berdasarkan kode, sorting jadwal film, serta pagination daftar film (5 film per halaman).       |
| 3  | Diya Naura Alifa | Implementasi modul Bioskop (bioskop.h & bioskop.cpp), termasuk proses pemesanan tiket, validasi usia untuk film R18+, perhitungan total pembayaran, penerapan diskon 10%, integrasi Queue dan Stack ke sistem pemesanan, serta pencetakan tiket. |
| 4  | Vina Widya Pratiwi | Implementasi modul Kursi (kursi.h & kursi.cpp), termasuk pengelolaan kursi menggunakan Array 2D (bool kursi[5][5]), inisialisasi kursi, tampilan denah kursi, pemilihan kursi, dan validasi kursi yang telah terisi.         |

---

# 📌 Kelebihan Project

✅ Menggabungkan berbagai konsep struktur data dalam satu sistem

* Linked List
* Queue
* Stack
* Pointer
* Array 2D
* Sorting
* Pagination

✅ Kode Modular

Program dipisahkan menjadi beberapa file sehingga:

* Mudah dibaca
* Mudah diperbaiki
* Mudah dikembangkan

✅ Cocok untuk Pembelajaran

Project dapat digunakan sebagai studi kasus implementasi struktur data dan OOP pada bahasa C++.

---

# 👨‍💻 Author

Kelompok 10

Project: Sistem Pemesanan Tiket Bioskop

Bahasa: C++

---

# 📜 Lisensi

Project ini dibuat untuk keperluan pembelajaran dan tugas akhir praktikum.
