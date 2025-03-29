hesap::hesap()
{
    loginDisplay();
}

void hesap::loginDisplay()
{
    int secim;
    do
    {
       
       cout<<"\n\n\t---------BURAKBANK'a Hosgeldiniz---------\n\n";

       cout<<setw(17)<<"1.Giris yap"<<setw(20)<<"2.Hesap olustur"<<setw(15) <<"3.Cikis yap"<<setw(23) <<"4.Admin Display\n";
       cout<<"\t\nSeciminiz:";
       cin>>secim;

       switch (secim)
       {
       case 1:
       hesap_giris(); break;
       case 2:
        hesap_olustur();break; 
       case 3:
        exit(1); break; 
       case 4:
        admin(); break; 
       default: 
    cout<<"\n--------------------------\n";

       cerr<<"hatali numara girisi\n";
    cout<<"\n--------------------------\n";

        break;
       }
    } while (secim!=3);
    
} 
 
void hesap::hesap_olustur(){
    string username,firstname,lastname;
    int password,kod,kulbakiye=0;
    srand(time(0));
    kod = rand() % 9000 + 1000;

    kullanici_id[count] = kod;
    
    cout<<"isim gir:";
    cin>>firstname;
    cout<<"soyisim gir:";
    cin>>lastname;
    cout<<"kullanici adi gir:";
    cin>>username;
    cout<<"sifre gir:";
    cin>>password;

    usernames[count] = new string(username);
    passwords[count] = new int(password);
    name[count] = new string(firstname);
    lastnames[count] = new string(lastname);
    bakiye[count] = new int(kulbakiye);
    

  
    count++;
    loginDisplay();
}

void hesap::hesap_giris()
{
    bool girisBasarili = false;
    string username;
    int password;
    cout<<"kullanici adinizi giriniz:";
    cin>>username;
    cout<<"sifrenizi giriniz:";
    cin>>password;
    
    for (int i = 0; i < count; i++)
    {
        if (*usernames[i] == username && *passwords[i] == password)
        {
            girisBasarili = true;
    cout<<"\n--------------------------\n";

            cout<<"\ngiris basarili! Hesabiniza gecis yapiliyor..\n";
    cout<<"\n--------------------------\n";

           
            islem yeniIslem(i, this);  //  Heap'te oluştur
           
            
            return;
        }
        
    }
    if (!girisBasarili)
    {
    cout<<"\n--------------------------\n";

        cout<<"giris basarisiz sifre yanlis\n";
    cout<<"\n--------------------------\n";

        if (count==0)
        {
            loginDisplay();
        }
        else
        hesap_giris();
        
    }
    
   
    
}

//admin display

void hesap::admin()
{
    int secim;
   
    do
    {
        cout<<"\n\t-----------------------------------";
        cout<<"\n\t       WELCOME IS DATABASE\n";
        cout<<"\t-----------------------------------\n\n";
        cout<<setw(17)<<"1.Hesap silme"<<setw(25) <<"2.hesaplari goruntule"<<setw(22)<<"3.anamenu'ye don"<<setw(17)<<"4.cikis yap\n";
        cout<<"\t\nSeciminiz:";
        cin>>secim;

        switch (secim)
        {
        case 1: hesapsil() ; break;
        case 2: hesaplarigoruntule(); break;
        case 3: loginDisplay(); break;
        case 4: exit(1); break;
        default:
            break;
        }
    } while (secim!=3);
    
    
}

void hesap::hesapsil(){
    int id;
    hesaplarigoruntule();
    cout << "\nsilmek istediginiz kisinin id'sini giriniz: ";
    cin >> id;

    for (int i = 0; i < count; i++) {

        if (id == kullanici_id[i]) {
            // Belleği serbest bırak
            delete usernames[i];
            delete name[i];
            delete lastnames[i];
            delete passwords[i];
            delete bakiye[i];

            // Diğer elemanları birer kaydır
            for (int j = i; j < count - 1; j++) {
                usernames[j] = usernames[j + 1];
                name[j] = name[j + 1];
                lastnames[j] = lastnames[j + 1];
                passwords[j] = passwords[j + 1];
                bakiye[j] = bakiye[j + 1];
                kullanici_id[j] = kullanici_id[j + 1];
            }

            // Son elemanı temizle
            usernames[count - 1] = nullptr;
            name[count - 1] = nullptr;
            lastnames[count - 1] = nullptr;
            passwords[count - 1] = nullptr;
            bakiye[count - 1] = nullptr;
            kullanici_id[count - 1] = 0;

            count--; // Kullanıcı sayısını bir azalt
    cout<<"\n--------------------------\n";

            cout << "\nBASARIYLA SILINDI!!\n";
    cout<<"\n--------------------------\n";

            return;
        }
    }
    cout<<"\n--------------------------\n";

    cout << "Kullanici bulunamadi!\n";
    cout<<"\n--------------------------\n";
    
   
    
}
void hesap::hesaplarigoruntule()
{
       cout << "\n\tid\t| kullanici adi\t| sifresi\t| adi\t| soyadi\t| bakiyesi\n";
    cout << "===============================================================================================================\n";

    for (int i = 0; i < count; i++) {
        if (kullanici_id[i] != 0) {
            cout <<i<<"     "
                 << setw(10) << left << kullanici_id[i] << " | "
                 << setw(10) << left << *usernames[i] << " | "
                 << setw(10) << left << *passwords[i] << " | "
                 << setw(10) << left << *name[i] << " | "
                 << setw(10) << left << *lastnames[i] << " | "
                 << setw(10) << left << *bakiye[i] << "\n";
        }
    }
   
}