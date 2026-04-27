
## [alpha-0.1.1] - 2026-04-27
### Added
- toplam hareket sayısı artık çıktı da veriliyor
- console refreshi yapıldı
- oyun sonu eklendi
- Şimdi map bu şekilde güzel bir şekilde basılıyor
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ X │ 0 │ 0 │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
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