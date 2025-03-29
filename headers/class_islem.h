
class islem{
    int kulbakiye;
    public:
    islem(int id, hesap* h);
    void anamenu(int id, hesap* h);
    void bakiyeSorgula(int bakiye);
    void para_cek(int* bakiye);
    void para_yatir(int* bakiye);
    void para_transferi(int* bakiye,hesap* h);
  
};