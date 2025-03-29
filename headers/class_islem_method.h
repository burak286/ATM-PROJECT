islem::islem(int id, hesap* h)
{   cout <<"\nid:"<<h->getkul_id(id) << endl;
    anamenu(id, h);
        
}

void islem::anamenu(int id, hesap* h)
{
    int secim;
    kulbakiye = h->getBakiye(id);
    
    
    
    do
    {
       
    

       cout<<"\n"<<setw(17)<<"1.Bakiye sorgula"<<setw(19)<<"2.Para yatir"<<setw(17) <<"3.Para cek"<<setw(19)<<"4.Para transferi"<<setw(19)<<"5.anamenuye'don"<<setw(19)<<"6.cikis yap\n";
       cout<<"\t\nSeciminiz:";
       cin>>secim;
    
       switch (secim)
       {
       case 1:
       bakiyeSorgula(kulbakiye); break;
       case 2:
       para_yatir(&kulbakiye);h->setBakiye(id,kulbakiye); break; 
       case 3:
       para_cek(&kulbakiye);h->setBakiye(id,kulbakiye); break; 
       case 4:
       para_transferi(&kulbakiye,h) ;h->setBakiye(id,kulbakiye); break; 
       case 5: h->loginDisplay(); break; 
       case 6: exit(1); break; 


       default:
    cout<<"\n--------------------------\n";

        cerr<<"hatali numara girisi\n";
    cout<<"\n--------------------------\n";

        break;
       }
    } while (secim!=5);

}

void islem::bakiyeSorgula(int bakiye)
{
    cout<<"\n--------------------------\n";
    cout<<"\nbakiyeniz:"<<bakiye<<"\n";
    cout<<"\n--------------------------\n";

}

void islem::para_yatir(int* bakiye)
{
    int nakit;
    cout<<"\nyatirmak istediginiz tutari giriniz:";
    cin>>nakit;
    if (nakit>0)
    {
        *bakiye+=nakit;
    cout<<"\n--------------------------\n";

        cout<<"\npara yatirma islemi basarili!\n";
        cout<<"\nguncel bakiye: "<<*bakiye<<"\n";
    cout<<"\n--------------------------\n";

       
    }
    else
    {
        cout<<"\n--------------------------\n";
        cout<<"\nyanlis tuslama yaptiniz!\n";
        cout<<"\n--------------------------\n";
    }
    
    
    
}

void islem::para_cek(int* bakiye)
{
    int nakitCek;
    cout<<"\ncekmek istediginiz tutari giriniz:";
    cin>>nakitCek;
    
    if (nakitCek>0)
    {
    cout<<"\n--------------------------\n";

        *bakiye-=nakitCek;
        cout<<"\npara cekme islemi basarili!\n";
        cout<<"\nguncel bakiye: "<<*bakiye<<"\n";
    cout<<"\n--------------------------\n";

    }
    else
    {
    cout<<"\n--------------------------\n";

        cout<<"\nyanlis tuslama yaptiniz!\n";
    cout<<"\n--------------------------\n";

    }    
}

void islem::para_transferi(int* bakiye, hesap* h)
{
    int tutar,id,alici_id;
    
    cout<<"para gondermek istediginiz kisinin id'sini giriniz:";
    cin>>id;
    cout<<"gondermek istediginiz tutari giriniz:";
    cin>>tutar;

    if (*bakiye>=tutar)
    {
        bool transfer_basarili = false;
        for (int i = 0; i < h->getcount(); i++)
        {
            if (id == h->getkul_id(i))
            {
    
                *bakiye-=tutar;
    
                h->setBakiye(i,h->getBakiye(i)+tutar);
    
                transfer_basarili=true;
    cout<<"\n--------------------------\n";

                cout<<"\n transfer basariyla gerceklesti..\n";
    cout<<"\n--------------------------\n";

            }
            
            
        }
        cout<<"\n--------------------------\n";
    
        if (!transfer_basarili)  cout<<"\nbu id'ye sahip bir kullanici bulunamadi!\n";
    cout<<"\n--------------------------\n";

    }
    else{
    cout<<"\n--------------------------\n";

    cout<<"\nBakiyeniz yeterli degil!\n";
    cout<<"\n--------------------------\n";

    para_transferi(&kulbakiye,h);
    }   
    
    
}