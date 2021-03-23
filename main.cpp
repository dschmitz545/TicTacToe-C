#include <wx/wxchar.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <string.h>

class jogoVelha : public wxApp {    //criando o aplicativo principal
public:
    virtual bool OnInit();          //Método que vai iniciar o aplicativo
};

class MainFrame : public wxFrame {  // Criando a janela
public:
    MainFrame();                    // o construtor da classe
protected:
    wxMenuBar* m_mainMenuBar;       // os menus da janela
    wxMenu* m_menuGame;
    wxMenu* m_menuHelp;
private:
    void OnNewGame(wxCommandEvent& event);  //métodos dos menus
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

bool jogoVelha::OnInit(){
    MainFrame* frame = new MainFrame();     //iniciando um novo objeto
    frame->Show();

    //alterar no futuro

    return true;
}

enum {
    ID_NewGame = 1
};

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Meu Jogo da Velha"){ // para a classe MainFrame, crio o construtor dela
    this->SetSizeHints(600,600); //tamanho da janela, em pixels
    
    m_mainMenuBar = new wxMenuBar(0);
    m_menuGame = new wxMenu();
    m_menuHelp = new wxMenu();

    m_mainMenuBar->Append(m_menuGame, "Game");
    m_mainMenuBar->Append(m_menuHelp, "Help");

    m_menuGame->Append(ID_NewGame, "&New Game\tCtrl-N", "Start a new match");
    m_menuGame->AppendSeparator();
    m_menuGame->Append(wxID_EXIT);

    m_menuHelp->Append(wxID_ABOUT);

    wxFont font(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

    this->SetMenuBar(m_mainMenuBar);

    Bind(wxEVT_MENU, &MainFrame::OnNewGame, this, ID_NewGame); //Bind vai associar o evento menu
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
}

wxIMPLEMENT_APP(jogoVelha);

void MainFrame::OnNewGame(wxCommandEvent& event){
    wxMessageBox("Teste 1", "New Game", wxOK | wxICON_INFORMATION);

};
void MainFrame::OnExit(wxCommandEvent& event){
   Close(true);
};
void MainFrame::OnAbout(wxCommandEvent& event){
    wxMessageBox("Exemplo de um Jogo da Velha feito em C/C++", "Sobre Jogo da Velha", wxOK | wxICON_WARNING);
};