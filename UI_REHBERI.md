# ATM Projesine Arayüz Ekleme Rehberi

Bu proje şu an tamamen `cin/cout` ile terminale bağlı çalışıyor. Arayüz (GUI/Web) eklemek için en doğru yol, **iş kurallarını** (hesap açma, giriş, para yatırma/çekme/transfer) ekrandan ayırmaktır.

## 1) Önce mevcut yapıyı ayır

Mevcutta kullanıcıdan veri alma ve iş kuralı aynı fonksiyonlarda:
- `hesap::hesap_olustur`, `hesap::hesap_giris`, `islem::para_yatir`, `islem::para_cek`, `islem::para_transferi`

Hedef:
- Fonksiyonlar parametre alsın, `cout/cin` yapmasın.
- Ekran katmanı sadece formdan veri toplayıp bu fonksiyonları çağırsın.

Örnek hedef imzalar:
- `bool hesapOlustur(string ad, string soyad, string username, int sifre)`
- `int girisYap(string username, int sifre)` → kullanıcı index/id döner
- `bool paraYatir(int kullaniciIndex, int tutar)`
- `bool paraCek(int kullaniciIndex, int tutar)`
- `bool paraTransfer(int gonderenIndex, int aliciId, int tutar)`

## 2) Hızlı arayüz seçenekleri

### Seçenek A (en hızlı): Python Tkinter
- C++ kodunu aynen bırakıp mantığı Python'da yeniden yazmak kısa vadede hızlıdır.
- Dezavantaj: iki farklı dilde kod tabanı olur.

### Seçenek B (önerilen): C++ Qt Widgets
- Aynı dilde kalırsın.
- Login ekranı, kayıt ekranı, kullanıcı paneli (bakiye/yatır/çek/transfer) kolay yapılır.

### Seçenek C: Web arayüz
- Backend (C++ REST API) + Frontend (React/Vue).
- En profesyonel ama en fazla efor.

## 3) Bu repo için önerilen yol (Qt)

1. `ATMService` gibi bir sınıf oluştur; tüm bankacılık işlemleri burada olsun.
2. `MainWindow` (giriş), `RegisterDialog`, `DashboardWindow` pencerelerini ekle.
3. Buton click event'lerinde `ATMService` çağır.
4. Sonuçları `QMessageBox` ile göster.

## 4) Ekran akışı

1. Açılış: "Giriş Yap" / "Hesap Oluştur"
2. Giriş başarılıysa: Dashboard
3. Dashboard:
   - Bakiye Gör
   - Para Yatır
   - Para Çek
   - Transfer
   - Çıkış

## 5) Kritik teknik iyileştirmeler (GUI öncesi)

- Ham pointer yerine `std::vector` + struct kullan.
- Recursive menü çağrılarını kaldır (`loginDisplay()` içinde tekrar çağırma gibi).
- `para_cek` içinde eksi bakiyeyi engelle.
- Giriş ve transfer için doğrulama mesajlarını fonksiyon dönüş değerleriyle yönet.

## 6) Minimum başlangıç planı (1-2 gün)

- Gün 1:
  - İş kurallarını `ATMService` içine taşı.
  - Terminal menüyü sadece bu servisi kullanan ince katman yap.
- Gün 2:
  - Qt ile 2 ekran yap: Login + Dashboard.
  - Para yatır/çek/bakiye sorguyu bağla.

---

İstersen bir sonraki adımda bu repoya doğrudan:
- `ATMService` sınıfını çıkarıp,
- terminalden bağımsız hale getirip,
- üstüne Qt için hazır iskelet dosyaları
ekleyebilirim.
