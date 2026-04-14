#set page(margin: 0pt, width: 210mm, height: 297mm)
#set text(font: "DejaVu Sans", lang: "id", size: 11pt)

#pad(x: 2cm, y: 2cm)[
  #align(center)[
    #text(size: 24pt, weight: "bold")[Rangkuman: Metode Pengukuran] \
    #text(size: 11pt, weight: "medium")[Instrumen Listrik, Karakteristik, Analisis Kesalahan, Pemrosesan Sinyal, dan Pengukuran Temperatur] \
    #line(length: 100%, stroke: 1pt)
  ]

  #v(1em)

  = I. Klasifikasi Instrumen
  Sebelum masuk ke alat ukur spesifik, kita harus memahami bagaimana instrumen dikelompokkan berdasarkan cara kerja dan outputnya:

  == 1. Aktif vs Pasif
  - *Instrumen Pasif:* Instrumen yang tidak memerlukan sumber energi luar. Output energinya murni berasal dari besaran yang diukur.
    - *Contoh:* Alat pengukur tekanan (pressure gauge) mekanik. Tekanan fluida langsung mendorong pegas dan jarum.
  - *Instrumen Aktif:* Memerlukan sumber energi eksternal (power source). Besaran yang diukur hanya bertugas "memodulasi" energi eksternal tersebut.
    - *Contoh:* Indikator level tangki bensin. Pelampung mengubah hambatan listrik, tapi energi untuk menggerakkan jarum di dashboard berasal dari baterai mobil.

  == 2. Null-type vs Deflection-type
  - *Deflection-type:* Nilai diukur berdasarkan besarnya penyimpangan jarum atau angka. Sangat praktis digunakan sehari-hari.
    - *Contoh:* Timbangan pegas (jarum bergerak sesuai berat benda).
  - *Null-type:* Mencapai keseimbangan hingga indikator menunjukkan angka nol (null). Jauh lebih akurat karena tidak membebani sistem yang diukur, tapi kurang praktis.
    - *Contoh:* Timbangan lengan tradisional (kita menambah beban lawan sampai kedua sisi sejajar/nol).

  == 3. Analog vs Digital
  - *Analog:* Output berubah secara kontinu (terus-menerus). Memiliki jumlah nilai tak terhingga dalam rentangnya.
  - *Digital:* Output berubah dalam langkah-langkah diskrit. Hanya memiliki nilai-nilai tertentu yang terbatas.

  == 4. Indikasi vs Output Sinyal
  - *Indikasi:* Hanya memberikan tampilan visual atau audio untuk manusia (seperti termometer biasa).
  - *Output Sinyal:* Menghasilkan sinyal listrik (voltase/arus) atau optik yang bisa dikirim ke sistem kontrol otomatis atau komputer.

  == 5. Smart Instruments
  Instrumen yang memiliki mikroprosesor di dalamnya untuk melakukan pengolahan data otomatis, kalibrasi mandiri, atau kompensasi gangguan.

  #v(1em)

  = II. Karakteristik Statis Instrumen
  Karakteristik statis menentukan seberapa baik performa alat ukur saat mengukur besaran yang nilainya tetap atau berubah sangat lambat.

  == 1. Akurasi & Inakurasi (Ketidakpastian)
  - *Akurasi:* Seberapa dekat hasil pengukuran dengan nilai yang sebenarnya.
  - *Inakurasi:* Besarnya kemungkinan kesalahan, biasanya dinyatakan dalam persen terhadap skala penuh (*Full Scale* atau f.s.).
    - *Contoh:* Alat ukur tekanan 0-10 bar dengan inakurasi 1% f.s. Artinya, kesalahan maksimal adalah $1% times 10 = 0,1$ bar. Jika alat membaca 1 bar, error 0,1 bar itu berarti kesalahannya mencapai 10% dari nilai yang sedang dibaca!

  == 2. Presisi (Repeatability & Reproducibility)
  Presisi adalah kemampuan alat memberikan hasil yang sama untuk input yang sama berkali-kali (bebas dari error acak).
  - *Repeatability:* Hasil tetap sama jika orangnya sama, alatnya sama, lokasinya sama, dan dilakukan dalam waktu singkat.
  - *Reproducibility:* Hasil tetap sama meskipun orang, alat, lokasi, atau waktunya berbeda.

  == 3. Linearitas
  Diharapkan output alat ukur berbanding lurus dengan inputnya ($y = m x + b$). Jika grafiknya melengkung, maka alat tersebut memiliki error non-linearitas.

  == 4. Sensitivitas
  Rasio antara perubahan output terhadap perubahan input.
  $K = "Perubahan Output" / "Perubahan Input"$
  - *Contoh:* Jika suhu naik $30 degree C$ dan hambatan sensor naik $7 Omega$, maka sensitivitasnya adalah $7/30 = 0,233 Omega/degree C$.

  == 5. Threshold & Resolusi
  - *Threshold:* Nilai input minimal agar alat mulai memberikan respon/perubahan output. (Ibarat "tenaga minimal" agar jarum mulai bergerak dari nol).
  - *Resolusi:* Perubahan input terkecil yang masih bisa dideteksi oleh alat ukur.

  == 6. Gangguan (Drift)
  Kondisi lingkungan (seperti suhu atau tekanan udara) bisa mengganggu hasil ukur:
  - *Zero Drift (Bias):* Seluruh grafik pembacaan bergeser naik atau turun (titik nol berubah).
  - *Sensitivity Drift:* Kemiringan grafik berubah (alat menjadi terlalu sensitif atau kurang sensitif).

  == 7. Histeresis & Dead Space
  - *Histeresis:* Perbedaan hasil ukur saat nilai input didekati dari bawah (naik) dibandingkan saat didekati dari atas (turun).
  - *Dead Space:* Rentang nilai input di mana alat sama sekali tidak memberikan respon output.

  #v(1em)

  = III. Karakteristik Dinamis Instrumen
  Karakteristik dinamis menjelaskan bagaimana perilaku alat ukur jika besaran yang diukur berubah dengan cepat terhadap waktu.

  == 1. Kecepatan Respon & Waktu Respon
  - *Kecepatan Respon (Speed of Response):* Seberapa cepat alat menanggapi perubahan input.
  - *Waktu Respon (Response Time):* Waktu yang dibutuhkan alat untuk "tenang" (settle) di posisi akhirnya setelah diberi input. Biasanya diukur sampai mencapai 90% atau 99% dari nilai akhir.

  == 2. Lag (Keterlambatan)
  Keterlambatan antara perubahan input dengan respon output. Ada dua jenis:
  - *Retardation:* Respon langsung dimulai begitu input berubah, tapi butuh waktu untuk sampai ke nilai akhir.
  - *Time Delay:* Ada jeda waktu (dead zone) di mana alat tidak memberikan respon sama sekali di awal, baru kemudian mulai bergerak.

  == 3. Fidelity (Kesetiaan)
  Kemampuan alat untuk menghasilkan output yang bentuknya *persis sama* dengan inputnya tanpa ada distorsi.
  - *Contoh:* Jika suhu naik secara linear, maka grafik output alat juga harus naik secara linear tanpa melengkung-melengkung tak jelas.

  == 4. Dynamic Error
  Selisih antara nilai sebenarnya dengan nilai yang ditunjukkan alat saat besaran tersebut sedang berubah terhadap waktu.

  == 5. Orde Instrumen (Orde Sistem)
  Berdasarkan persamaan matematiknya, instrumen dibagi menjadi:
  - *Orde Nol (Zero Order):* Output langsung mengikuti input tanpa ada hambatan atau delay ($q_o = K q_i$).
    - *Contoh:* Potensiometer. Begitu digeser, tegangan langsung berubah seketika.
  - *Orde Satu (First Order):* Memiliki hambatan penyimpanan energi (seperti kapasitas panas). Output tidak langsung mencapai nilai akhir, tapi merambat pelan mengikuti konstanta waktu ($tau$).
    - *Contoh:* Termometer air raksa. Saat dicelupkan ke air panas, butuh waktu bagi air raksa untuk memanas dan naik.
  - *Orde Dua (Second Order):* Memiliki elemen massa dan pegas yang bisa menyebabkan osilasi (getaran) sebelum akhirnya tenang. Sangat dipengaruhi oleh rasio redaman ($xi$).

  #v(1em)

  = IV. Kalibrasi
  Alat ukur baru biasanya sudah dikalibrasi oleh pabrik. Namun, seiring waktu, performa alat akan menurun akibat:
  - Keausan mekanik (gesekan).
  - Pengaruh kotoran, debu, dan uap kimia.
  - Perubahan kondisi lingkungan.

  *Pentingnya Kalibrasi:* Kalibrasi berkala sangat diperlukan untuk memastikan alat tetap memberikan hasil yang akurat sesuai spesifikasi standarnya. Jika tidak dikalibrasi, error akan menumpuk dan hasil pengukuran tidak bisa lagi dipercaya.

  #v(1em)

  = V. Analisis Kesalahan (Error Analysis)
  Tidak ada pengukuran yang benar-benar sempurna. Selalu ada selisih antara nilai yang ditunjukkan alat dengan nilai sebenarnya. Selisih inilah yang disebut *error*.

  == 1. Kesalahan Sistematik (Systematic Error)
  Kesalahan yang sifatnya konsisten dan bisa diprediksi penyebabnya. Jika Anda mengukur 10 kali, kesalahannya akan selalu sama (misal selalu lebih tinggi 2 unit).
  - *Gangguan Sistem (System Disturbance):* Tindakan mengukur itu sendiri merubah apa yang diukur.
    - *Contoh:* Anda ingin mengukur suhu sebongkah es kecil menggunakan termometer air raksa yang besar dan hangat. Panas dari termometer akan masuk ke es, sehingga es tersebut sedikit mencair dan suhunya berubah. Hasil ukur Anda bukan lagi suhu asli es tersebut.
  - *Masukan Lingkungan (Environmental Inputs):* Suhu atau tekanan di sekitar alat yang mempengaruhi performa komponen internal alat.
  - *Keausan Alat:* Komponen mekanik yang aus seiring waktu.
  - *Connecting Leads:* Gangguan atau hambatan pada kabel penghubung.

  *Cara Mengurangi Kesalahan Sistematik:*
  - *Desain Instrumen yang Hati-hati:* Menggunakan material yang tidak sensitif terhadap lingkungan.
  - *Metode Opposing-Input:* Memasukkan gangguan yang berlawanan untuk saling meniadakan. Contoh: Kabel *UTP (Twisted Pair)* dipilin agar gangguan listrik saling hapus.
  - *Umpan Balik Gain Tinggi (High-gain Feedback):* Menstabilkan sistem agar tidak gampang goyang oleh gangguan luar.
  - *Kalibrasi Berkala:* Solusi paling efektif untuk mengatasi keausan.

  == 2. Kesalahan Acak (Random Error)
  Kesalahan yang tidak bisa diprediksi, muncul sebagai gangguan kecil yang acak di sekitar nilai asli (bisa lebih tinggi atau lebih rendah).
  - *Solusi:* Melakukan pengukuran berulang-ulang lalu mengambil nilai rata-ratanya. Secara statistik, kesalahan positif dan negatif akan saling meniadakan jika sampelnya banyak.

  == 3. Analisis Statistik Kesalahan Acak
  Untuk data sebanyak $n$:
  - *Mean (Rata-rata):* $x_"mean" = (x_1 + x_2 + dots + x_n) / n$.
  - *Median:* Nilai tengah setelah data diurutkan dari terkecil ke terbesar.
  - *Deviasi Standar ($sigma$):* Seberapa jauh data menyebar dari rata-ratanya. $sigma = sqrt((sum (x_i - x_"mean")^2) / (n-1))$. Semakin kecil $sigma$, semakin presisi alat tersebut.
  - *Standard Error of Mean ($alpha$):* Ketidakpastian dari nilai rata-rata, $alpha = sigma / sqrt(n)$.

  == 4. Distribusi Gaussian (Normal)
  Data pengukuran yang hanya mengandung kesalahan acak akan membentuk kurva lonceng (Gaussian). Data paling banyak akan berkumpul di dekat nilai rata-rata.

  == 5. Penggabungan Kesalahan (Aggregation of Errors)
  Jika hasil akhir dihitung dari beberapa sensor yang masing-masing punya error:
  - *Penjumlahan & Pengurangan:* $e = sqrt((a y)^2 + (b z)^2)$ (menggunakan error absolut).
  - *Perkalian & Pembagian:* $e = sqrt(a^2 + b^2)$ (menggunakan error relatif/persen).
    - *Contoh:* Jika Anda menghitung daya ($P = V times I$) di mana tegangan ($V$) punya error 1% dan arus ($I$) punya error 2%, maka error total daya adalah $sqrt(1^2 + 2^2) = 2,23%$.

  #v(1em)

  = VI. Noise Pengukuran dan Pemrosesan Sinyal
  Dalam sistem pengukuran elektronik, sinyal seringkali tercampur dengan gangguan yang tidak diinginkan yang disebut *Noise*.

  == 1. Apa itu Noise?
  Noise adalah sinyal acak yang tidak diinginkan yang mengganggu sinyal pengukuran asli. Kualitas sinyal dinyatakan dalam *Signal-to-Noise Ratio (SNR)*:
  $"SNR" = 20 log_10 (V_s / V_n)$
  Di mana $V_s$ adalah voltase sinyal dan $V_n$ adalah voltase noise. Semakin tinggi SNR, semakin bersih sinyalnya.

  == 2. Sumber-sumber Noise
  - *Inductive Coupling:* Terjadi karena kabel sinyal berdekatan dengan kabel listrik PLN atau peralatan yang dialiri arus besar. Medan magnet dari kabel listrik menginduksi voltase noise pada kabel sinyal.
  - *Capacitive Coupling:* Terjadi karena adanya kapasitansi parasit antara kabel sinyal dengan sumber gangguan listrik statis.
  - *Multiple Earths (Ground Loop):* Terjadi jika sistem memiliki lebih dari satu titik grounding dengan potensi listrik yang berbeda, menyebabkan arus mengalir di kabel ground dan mengganggu sinyal.
  - *Voltage Transients (Spikes):* Gangguan mendadak (seperti lonjakan voltase) saat motor atau saklar lampu dinyalakan/dimatikan.
  - *Thermal & Shot Noise:* Noise yang muncul dari dalam komponen elektronik itu sendiri akibat pergerakan acak elektron.

  == 3. Teknik Mengurangi Noise
  - *Tata Letak Kabel:* Menjauhkan kabel sinyal dari kabel daya (PLN).
  - *Earthing (Grounding):* Memastikan sistem pembumian yang benar. Ada beberapa jenis ground: *Power ground, Logic ground, Analogue ground,* dan *Safety ground*.
  - *Shielding:* Membungkus kabel sinyal dengan pelindung logam (seperti kabel koaksial) untuk memblokir gangguan elektromagnetik.

  == 4. Pemrosesan Sinyal Analog
  - *Filtering (Penyaringan):* Membuang frekuensi yang tidak diinginkan.
    - *Low-pass Filter:* Hanya meloloskan frekuensi rendah (membuang noise frekuensi tinggi).
    - *High-pass Filter:* Hanya meloloskan frekuensi tinggi.
    - *Band-pass Filter:* Meloloskan rentang frekuensi tertentu.
    - *Band-stop Filter:* Menghilangkan satu rentang frekuensi tertentu (misal menghilangkan dengung PLN 50Hz).
  - *Amplification (Penguatan):* Memperbesar amplitudo sinyal yang lemah menggunakan *Operational Amplifier (Op-Amp)*.
  - *Linearization:* Mengubah sinyal non-linear (seperti dari termistor) menjadi linear secara matematis.

  == 5. Pemrosesan Sinyal Digital
  - *Sampling:* Proses mengambil cuplikan sinyal analog pada interval waktu tertentu untuk diubah menjadi data digital.
  - *ADC (Analogue-to-Digital Converter):* Mengubah voltase analog menjadi angka digital.
  - *DAC (Digital-to-Analogue Converter):* Mengubah angka digital kembali menjadi voltase analog.

  #v(1em)

  = VII. Elemen Konversi Variabel: Rangkaian Jembatan
  Sensor seringkali menghasilkan perubahan resistansi, induktansi, atau kapasitansi yang sangat kecil. Rangkaian jembatan digunakan untuk mengubah perubahan kecil tersebut menjadi sinyal voltase yang mudah diukur.

  == 1. Jembatan Wheatstone (D.C. Bridge)
  Metode paling umum untuk mengukur resistansi menengah.
  - *Null-type:* Digunakan untuk pengukuran sangat akurat (akurasi hingga $plus.minus 0,02%$). Jembatan diseimbangkan sampai detektor menunjukkan nol.
  - *Deflection-type:* Output voltase jembatan dibaca langsung. Lebih praktis untuk sistem kontrol otomatis tapi kurang akurat dibanding tipe null.

  == 2. A.C. Bridges
  Digunakan untuk mengukur impedansi (Induktansi $L$ dan Kapasitansi $C$).
  - *Maxwell Bridge:* Digunakan khusus untuk mengukur induktansi.
  - *Wien Bridge:* Digunakan untuk mengukur frekuensi sinyal audio. Sangat akurat di frekuensi rendah, tapi error meningkat di frekuensi tinggi karena efek kapasitansi liar.

  #v(1em)

  = VIII. Instrumen Indikasi dan Pengujian Listrik
  Instrumen ini digunakan untuk menampilkan nilai besaran listrik (voltase, arus, frekuensi) secara langsung.

  == 1. Digital Meters
  Semua meter digital (voltmeter, multimeter) pada dasarnya adalah bentuk modifikasi dari *Digital Voltmeter (DVM)*.
  - *Kelebihan:* Akurasi tinggi, impedansi input tinggi (tidak membebani rangkaian), dan mudah dibaca (angka langsung keluar).

  == 2. Analogue Meters
  Menggunakan jarum dan skala fisik. Meskipun mulai digantikan digital, masih digunakan karena murah dan tidak butuh baterai (untuk tipe pasif).
  - *Moving-coil meter:* Jenis paling umum untuk arus searah (DC).
  - *Moving-iron meter:* Bisa digunakan untuk arus bolak-balik (AC).

  == 3. Clamp-on Meter (Tang Ampere)
  Alat ukur arus yang unik karena tidak perlu memutus kabel. Cukup "mencapit" kabel, dan sensor akan mendeteksi medan magnet untuk mengetahui besarnya arus listrik. Sangat aman dan praktis untuk teknisi lapangan.

  == 4. Osiloskop (Oscilloscope)
  Instrumen pengujian paling canggih yang menampilkan bentuk gelombang sinyal terhadap waktu.
  - *Fungsi Utama:* Mengukur voltase, frekuensi ($f = 1/T$), dan beda fasa antara dua sinyal (menggunakan pola *Lissajous*).

  == 5. Pengukuran Frekuensi & Fasa
  - *Digital counter-timer:* Menghitung jumlah pulsa dalam interval waktu tertentu.
  - *Phase-locked loop (PLL):* Teknik elektronik untuk melacak dan mengukur frekuensi serta fasa sinyal secara otomatis.

  #v(1em)
  #line(length: 100%, stroke: 0.5pt + gray)
  #v(1em)

  = IX. Fokus: Pengukuran Temperatur
  Berikut adalah aplikasi nyata pada berbagai sensor suhu yang bekerja berdasarkan prinsip fisik yang berbeda:

  == 1. Sensor Efek Termoelektrik (Thermocouple)
  Bekerja berdasarkan *Efek Seebeck*: Dua logam berbeda yang disambung akan menghasilkan tegangan listrik (mV) jika ada perbedaan suhu antara ujung sambungan dan ujung ukur.
  - *Tipe K:* Paling umum (Chromel-Alumel).
  - *Tipe R & S:* Sangat akurat untuk suhu tinggi (Platina).

  == 2. Resistance Thermometer (RTD)
  Menggunakan logam murni (seperti Platina PT100). Resistansi logam *naik* secara linear saat suhu naik.
  $R approx R_0 (1 + alpha_1 T)$

  == 3. Termistor (Thermistor)
  Terbuat dari semikonduktor. Sangat sensitif terhadap perubahan suhu kecil, tapi hubungannya tidak linear (eksponensial).

  == 4. Sensor Semikonduktor (IC)
  Seperti *LM35*. Sangat mudah digunakan karena mengeluarkan tegangan yang langsung sebanding dengan suhu Celcius (misal $10 m V / degree C$).

  == 5. Termometer Radiasi & Termografi
  Mengukur suhu tanpa menyentuh benda.
  - *Prinsip:* Mengukur radiasi infra merah yang dipancarkan benda ($E = K T^4$).
  - *Termografi:* Mengubah radiasi menjadi gambar visual peta suhu.

  == 6. Metode Ekspansi Termal (Pemuaian)
  - *Liquid-in-glass:* Air raksa/alkohol dalam kaca.
  - *Bimetallic Strip:* Dua logam yang ditempel dan melengkung saat panas karena beda kecepatan muai.
  - *Pressure Thermometer:* Perubahan tekanan gas/uap dalam tabung tertutup.

  == 7. Metode Khusus
  - *Quartz:* Menggunakan perubahan frekuensi resonansi kristal.
  - *Akustik:* Menggunakan kecepatan suara dalam gas (untuk suhu sangat ekstrim hingga $20.000 degree C$).
  - *Warna:* Label atau cat yang berubah warna (ada yang bisa balik/reversible, ada yang permanen).
]
