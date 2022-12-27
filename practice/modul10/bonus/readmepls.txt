1. prosedur modifydata aku ubah jadi fungsi yang bakal ngembaliin nilai banyak data di dalam tipe terstruktur.
   penjelasan:
- INSERT itu kan bakal nambah data ke tipe terstruktur, nah kalau berhasil nambah data program bakal nge-return 1
- UPDATE itu kan cuman ngeganti data doang, kalau berhasil ngubah data program bakal nge-return 0
- DELETE itu kan bakal ngehapus data di tipe terstruktur, nah kalau berhasil hapus data program bakal nge-return -1
- jika INSERT/UPDATE/DELETE-nya itu error, entah nama tabelnya salah / ketika INSERT nim-nya udah ada/ ketika UPDATE,DELETE nim-nya gaada, program bakal nge-return 0
- nah hasil return itu bakal ditampung di variabel sum

2. parameter di fungsi modifydata juga aku tambahin 3 biji
- parameter j itu buat nampung jumlah data di dalam tipe terstruktur / variabel sum 
- parameter idxquery itu buat nampung nomor perintah / variabel i
- parameter error itu buat tanda perintah kita berhasil jalan / error.

3. jika perintah yang masuk ke fungsi modifydata itu error, si variabel error di parameter itu bakal keganti jadi 1, yang artinya perintah tsb error

4. nah beres masuk ke fungsi modifydata, bakal di cek dulu, perintah tadi itu error/ngga
- selama perintah yang dimasukin user itu error, program bakal terus minta perintah sampe perintah tsb bener baru bisa lanjut ke perintah selanjutnya (kalau ada)

----contoh test case------------ (klo masukin test case harus satu satu, soalnya kalau perintahnya error program bakal langsung minta masukan lagi)
INPUT:
7.
INSERT mahasiswa 0001 Aldian A;
INSERT mahasiswa 0002 Carla B;
INSERT mahasiswa 0003 Freya A-;
UPDATE mahsiswa 0002 Carla B+;
==================================================================
Query ke-4 salah, tabel mahsiswa tidak ada!
==================================================================
masukkan revisi:
UPDATE mahasswa 0002 Carla B-;
==================================================================
Query ke-4 salah, tabel mahasswa tidak ada!
==================================================================
masukkan revisi:
UPDATE mahasiswa 0002 Carla B+;
INSERT mahasisw 0004 Techi A+;
==================================================================
Query ke-5 salah, tabel mahasisw tidak ada!
==================================================================
masukkan revisi:
INSERT mahasiswa 0004 Techi A+;
DELETE mahasiswa 0007;
==================================================================
Query ke-6 salah, data nim 0007 tidak ada!
==================================================================
masukkan revisi:
DELETE mahasiswa 0003;
DELETE ahasiswa 0002;
==================================================================
Query ke-7 salah, tabel ahasiswa tidak ada!
==================================================================
masukkan revisi:
DELETE mahasiswa 0002;

OUTPUT :
1. 0001 Aldian A
2. 0004 Techi A+

----contoh test case------------
INPUT:
6.
INSERT mahasiswa 0001 Aldian A;
INSERT mahasiswa 0002 Carla B;
INSERT mahasiswa 0003 Freya A-;
UPDATE mahasiswa 0002 Carla B+;
INSERT mahasiswa 0004 Techi A+;
DELETE mahasiswa 0003;

OUTPUT:
1. 0001 Aldian A
2. 0002 Carla B+
3. 0004 Techi A+


   