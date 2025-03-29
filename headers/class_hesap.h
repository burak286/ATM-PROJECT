class hesap{

    int static count;

    protected:

 
    
    string* usernames[100],*name[100],*lastnames[100];
    int* passwords[100],kullanici_id[100],*bakiye[100];

    public:
    int getcount()
    {
        return count;
    }
    hesap();

    int getBakiye(int index) { return *bakiye[index]; }

    void setBakiye(int index,int newbakiye) {  
        *bakiye[index]=newbakiye; 
    }

    int getkul_id(int id) { return kullanici_id[id]; }
    
    void loginDisplay(); 
    void hesap_olustur(); 
    void hesap_giris(); 

    //admin display
    void admin();
    void hesapsil();
    void hesaplarigoruntule();
    

};





















