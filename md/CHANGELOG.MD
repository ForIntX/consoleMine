## [alpha-0.1.2] - 2026-05-01

### Added
* **Modüler Yapı:** Tek dosyadan oluşan (`gamev4.cpp`) yapı, `header/` ve `source/` klasörlerine bölünerek modüler hale getirildi.
* **Build Sistemi:** Projenin derleme sürecini yönetmek için bir `Makefile` eklendi.
* **Renderer Sınıfı:** Görselleştirme mantığı `Game` sınıfından ayrılarak `Renderer` sınıfına taşındı.
* **AI Dosya Entegrasyonu:** `ai/girdi.txt` üzerinden hamle okuma ve `ai/results.txt` dosyasına sonuç raporlama sistemi eklendi.
* **Log ve Kayıt Sistemi:** Oyunun anlık durumunu ve maden koordinatlarını takip eden `ai/kayit.txt` sistemi devreye alındı.
* **Renk Sabitleri:** Terminal renklendirme için ANSI renk kodları (`KIRMIZI`, `YESIL`, vb.) eklendi.

### Changed
* **Dosya Organizasyonu:** Sınıf tanımları (`.h`) ve implementasyonları (`.cpp`) birbirinden ayrıldı.
* **Harita Boyutu:** Test süreçlerini hızlandırmak adına varsayılan harita boyutu $3 \times 3$ olarak güncellendi.
* **Skor Hesaplama:** Maden toplama ve puanlama mantığı `CheckMineAndGetPoints` üzerinden daha optimize hale getirildi.

### Fixed
* **Bellek Yönetimi:** `Delete_mine` fonksiyonunda madenler silindikten sonra `nullptr` ataması yapılarak olası crash durumları engellendi.
* **Kod Temizliği:** `main.cpp` içeriği sadeleştirilerek oyunun başlatılması ve döngüsü daha okunabilir hale getirildi.


## [alpha-0.1.1] - 2026-04-27
### Added
- toplam hareket sayısı artık çıktı da veriliyor
- console refreshi yapıldı
- oyun sonu eklendi
- Şimdi map bu şekilde güzel bir şekilde basılıyor
┌───┬───┬───┬───┬───┬───┐
│ 0 │ 0 │ 0 │ 0 │ 0 │ c │
├───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ c │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┤
│ 0 │ d │ 0 │ d │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ X │ 0 │
├───┼───┼───┼───┼───┼───┤
│ 0 │ d │ 0 │ c │ 0 │ 0 │
└───┴───┴───┴───┴───┴───┘
### Fixed
- delete all mine fonksiyonu şimdilik silindi düzeltildiğinde geri yüklenecek


## [alpha-0.1.1] - 2026-04-24
### Added
- gameloopu playerdan alınıp game öğesi içerisine atandı
### Fixed
- Mine fonksiyonları düzeltilecek oluşturulan minelar bir dize haline getirilip pointer aracılığıyla tutulacak ardından bunun üzerinden ayarlanacak
- Şu anda her şeyi baştan sona oluşturuyor düzeltcez onu yani entity ögesi scope aralığında sürekli oluşup siliniyor
- şu anda 25lik bir dizi eğer ki bu dizi boyutu büyütülürse fonksiyonlar düzgün çalışmıyor düzeltilecek
- ekran yazdırma kısmında bir bug var tam anlamadım düzeltilecek(denemek için ekran boyutunu 10*10 bakır ve de demiri de 20 ye 10 yap)



## [alpha-0.1.0] - 2026-04-22
- İlk prototip oluşturuldu.
- Versiyonda eklenenler bakır,demir madenleri, oyuncu ögesi,map
- Ve çalışan bir oyun.