-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Waktu pembuatan: 04 Jan 2022 pada 03.33
-- Versi server: 10.4.22-MariaDB
-- Versi PHP: 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `basisdata_sekolah`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `guru`
--

CREATE TABLE `guru` (
  `nip` int(11) NOT NULL,
  `nama` varchar(50) NOT NULL,
  `alamat` text DEFAULT NULL,
  `tanggal_lahir` date DEFAULT NULL,
  `id_mapel` varchar(50) DEFAULT NULL,
  `jam_mengajar` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data untuk tabel `guru`
--

INSERT INTO `guru` (`nip`, `nama`, `alamat`, `tanggal_lahir`, `id_mapel`, `jam_mengajar`) VALUES
(1111111, 'Suryanto', 'Bantul', '0000-00-00', 'MTK01', '07.00-07.45'),
(1111112, 'Sri Asih', 'Sleman', '1978-10-12', 'IND01', '07.00-07.45'),
(1111113, 'Rahayu', 'Bnatul', '1979-07-09', 'ING02', '07.45-08.30'),
(1111114, 'Bayu', 'Magelang', '1969-03-11', 'FSK03', '08.30-09.25'),
(1111115, 'Dimas', 'Bantul', '1992-02-14', 'PJK02', '07.45-08.30');

-- --------------------------------------------------------

--
-- Struktur dari tabel `kelas`
--

CREATE TABLE `kelas` (
  `id_kelas` varchar(50) NOT NULL,
  `nama_kelas` varchar(50) NOT NULL,
  `status_kelas` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data untuk tabel `kelas`
--

INSERT INTO `kelas` (`id_kelas`, `nama_kelas`, `status_kelas`) VALUES
('A1', 'IPA 1', 'Dipakai'),
('A2', 'IPA 2', 'Dipakai'),
('A3', 'IPA 3', 'Dipakai'),
('S1', 'IPS 1', 'Dipakai'),
('S2', 'IPS 2', 'Dipakai');

-- --------------------------------------------------------

--
-- Struktur dari tabel `mapel`
--

CREATE TABLE `mapel` (
  `id_mapel` varchar(50) NOT NULL,
  `nama_mapel` varchar(50) NOT NULL,
  `id_kelas` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data untuk tabel `mapel`
--

INSERT INTO `mapel` (`id_mapel`, `nama_mapel`, `id_kelas`) VALUES
('FSK03', 'Fisika', 'A3'),
('IND01', 'Bahasa Indonesia', 'S2'),
('ING02', 'Bahasa Inggris', 'A2'),
('MTK01', 'Matematika', 'A1'),
('PJK02', 'Penjasorkes', 'S1');

-- --------------------------------------------------------

--
-- Struktur dari tabel `pengajaran`
--

CREATE TABLE `pengajaran` (
  `id_mapel` varchar(50) DEFAULT NULL,
  `id_kelas` varchar(50) DEFAULT NULL,
  `waktu_pelajaran` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data untuk tabel `pengajaran`
--

INSERT INTO `pengajaran` (`id_mapel`, `id_kelas`, `waktu_pelajaran`) VALUES
('ING02', 'A2', '45 Menit'),
('IND01', 'S2', '45 Menit'),
('FSK03', 'A3', '45 Menit'),
('PKJK02', 'S1', '45 Menit'),
('MTK01', 'A1', '45 Menit');

-- --------------------------------------------------------

--
-- Struktur dari tabel `pengurus_kelas`
--

CREATE TABLE `pengurus_kelas` (
  `nis` int(11) DEFAULT NULL,
  `nama` varchar(50) NOT NULL,
  `jabatan` varchar(50) NOT NULL,
  `id_kelas` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data untuk tabel `pengurus_kelas`
--

INSERT INTO `pengurus_kelas` (`nis`, `nama`, `jabatan`, `id_kelas`) VALUES
(15, 'Bagas', 'Ketua Kelas', 'A1'),
(72, 'Sinta', 'Wakil Ketua Kelas', 'S2'),
(92, 'Rani', 'Sekertaris', 'S1'),
(100, 'Hendi', 'Bendahara 1', 'A3'),
(17, 'Arya', 'Bendahara 2', 'A2');

-- --------------------------------------------------------

--
-- Struktur dari tabel `siswa`
--

CREATE TABLE `siswa` (
  `nis` int(11) NOT NULL,
  `nama` varchar(50) NOT NULL,
  `alamat` text DEFAULT NULL,
  `tanggal_lahir` date DEFAULT NULL,
  `id_kelas` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data untuk tabel `siswa`
--

INSERT INTO `siswa` (`nis`, `nama`, `alamat`, `tanggal_lahir`, `id_kelas`) VALUES
(15, 'Bagas', 'Bantul', '2004-09-12', 'A1'),
(17, 'Arya', 'Sleman', '2003-07-15', 'A2'),
(72, 'Sinta', 'Bantul', '2005-04-21', 'A3'),
(92, 'Rani', 'Prambanan', '2004-12-30', 'S1'),
(100, 'Hendi', 'Sleman', '2005-05-28', 'S2');

--
-- Indexes for dumped tables
--

--
-- Indeks untuk tabel `guru`
--
ALTER TABLE `guru`
  ADD PRIMARY KEY (`nip`),
  ADD KEY `id_mapel` (`id_mapel`);

--
-- Indeks untuk tabel `kelas`
--
ALTER TABLE `kelas`
  ADD PRIMARY KEY (`id_kelas`);

--
-- Indeks untuk tabel `mapel`
--
ALTER TABLE `mapel`
  ADD PRIMARY KEY (`id_mapel`),
  ADD KEY `id_kelas` (`id_kelas`);

--
-- Indeks untuk tabel `pengajaran`
--
ALTER TABLE `pengajaran`
  ADD KEY `id_mapel` (`id_mapel`),
  ADD KEY `id_kelas` (`id_kelas`);

--
-- Indeks untuk tabel `pengurus_kelas`
--
ALTER TABLE `pengurus_kelas`
  ADD KEY `id_kelas` (`id_kelas`),
  ADD KEY `nis` (`nis`);

--
-- Indeks untuk tabel `siswa`
--
ALTER TABLE `siswa`
  ADD PRIMARY KEY (`nis`),
  ADD KEY `id_kelas` (`id_kelas`);

--
-- Ketidakleluasaan untuk tabel pelimpahan (Dumped Tables)
--

--
-- Ketidakleluasaan untuk tabel `guru`
--
ALTER TABLE `guru`
  ADD CONSTRAINT `guru_ibfk_1` FOREIGN KEY (`id_mapel`) REFERENCES `mapel` (`id_mapel`);

--
-- Ketidakleluasaan untuk tabel `mapel`
--
ALTER TABLE `mapel`
  ADD CONSTRAINT `mapel_ibfk_1` FOREIGN KEY (`id_kelas`) REFERENCES `kelas` (`id_kelas`);

--
-- Ketidakleluasaan untuk tabel `pengajaran`
--
ALTER TABLE `pengajaran`
  ADD CONSTRAINT `pengajaran_ibfk_1` FOREIGN KEY (`id_mapel`) REFERENCES `mapel` (`id_mapel`),
  ADD CONSTRAINT `pengajaran_ibfk_2` FOREIGN KEY (`id_kelas`) REFERENCES `kelas` (`id_kelas`);

--
-- Ketidakleluasaan untuk tabel `pengurus_kelas`
--
ALTER TABLE `pengurus_kelas`
  ADD CONSTRAINT `pengurus_kelas_ibfk_1` FOREIGN KEY (`id_kelas`) REFERENCES `kelas` (`id_kelas`),
  ADD CONSTRAINT `pengurus_kelas_ibfk_2` FOREIGN KEY (`nis`) REFERENCES `siswa` (`nis`);

--
-- Ketidakleluasaan untuk tabel `siswa`
--
ALTER TABLE `siswa`
  ADD CONSTRAINT `siswa_ibfk_1` FOREIGN KEY (`id_kelas`) REFERENCES `kelas` (`id_kelas`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
