# Tasks / To-Do List

##  Devam Edenler (In Progress)
- [ ] **Dil Güncellemesi:** Kod içerisindeki Türkçe değişken ve fonksiyon isimlerinin (örn: `yer_tutucu_isim`, `koordinat`) tamamen İngilizceye çevrilmesi.
- [ ] **Bilgi Sistemi:** `Info()` fonksiyonunun oyunun tüm mekaniklerini (maden puanları, hareket kısıtları) içerecek şekilde güncellenmesi.

##  Planlanan Özellikler (Upcoming Features)
- [ ] **Engel (Obstacle) Sınıfı:** Oyuncunun üzerinden geçemeyeceği statik engellerin eklenmesi.
- [ ] **Dinamik Harita:** Sabit boyutlu harita yerine sonsuz (procedural) harita üretme mantığına geçilmesi.
- [ ] **3D Projeksiyon:** Haritayı düz bir zemin yerine bir küpün yüzeyleriymiş gibi simüle etme mantığı.
- [ ] **Gelişmiş Kayıt Sistemi:** Mevcut `kayit.txt` dosyasının sadece log tutmak yerine, oyunu o noktadan devam ettirebilecek bir "Load" sistemine dönüştürülmesi.

##  Refaktör ve Optimizasyon
- [ ] **Kod Tekrarları:** `place_mine` fonksiyonundaki demir ve bakır için ayrı ayrı dönen `while` döngülerinin generic bir yapıya çekilmesi.
- [ ] **Parametre Temizliği:** `place_player` gibi fonksiyonlarda kullanılmayan veya gereksiz gönderilen parametrelerin kaldırılması.
- [ ] **Renk Kullanımı:** Tanımlanan renk sabitlerinin `Renderer` sınıfında maden türlerine göre (Bakır=Turuncu, Demir=Gri vb.) aktif edilmesi.