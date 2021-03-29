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

    wxButton* m_btnUpLeft;
    wxButton* m_btnUpMid;
    wxButton* m_btnUpRight;

    wxButton* m_btnMidLeft;
    wxButton* m_btnMidMid;
    wxButton* m_btnMidRight;

    wxButton* m_btnLowLeft;
    wxButton* m_btnLowMid;
    wxButton* m_btnLowRight;

    wxStatusBar* m_StatusBar;

    char m_msgStatusBar[200];

private:
    void OnNewGame(wxCommandEvent& event);  //métodos dos menus
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OnBtnUpLeftClick(wxCommandEvent& event);   //métodos para cada botão
    void OnBtnUpMidClick(wxCommandEvent& event);
    void OnBtnUpRightClick(wxCommandEvent& event);

    void OnBtnMidLeftClick(wxCommandEvent& event);   //métodos para cada botão
    void OnBtnMidMidClick(wxCommandEvent& event);
    void OnBtnMidRightClick(wxCommandEvent& event);

    void OnBtnLowLeftClick(wxCommandEvent& event);   //métodos para cada botão
    void OnBtnLowMidClick(wxCommandEvent& event);
    void OnBtnLowRightClick(wxCommandEvent& event);
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

    
    wxGridSizer* gBoard = new wxGridSizer(3, 3, 0, 0);
    gBoard->SetMinSize(500, 500);

    m_btnUpLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnUpLeft->SetFont(font);
    gBoard->Add(m_btnUpLeft, 0, wxALL | wxEXPAND, 5);

    m_btnUpMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnUpMid->SetFont(font);
    gBoard->Add(m_btnUpMid, 0, wxALL | wxEXPAND, 5);

    m_btnUpRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnUpRight->SetFont(font);
    gBoard->Add(m_btnUpRight, 0, wxALL | wxEXPAND, 5);

    m_btnMidLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnMidLeft->SetFont(font);
    gBoard->Add(m_btnMidLeft, 0, wxALL | wxEXPAND, 5);

    m_btnMidMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnMidMid->SetFont(font);
    gBoard->Add(m_btnMidMid, 0, wxALL | wxEXPAND, 5);

    m_btnMidRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnMidRight->SetFont(font);
    gBoard->Add(m_btnMidRight, 0, wxALL | wxEXPAND, 5);

    m_btnLowLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnLowLeft->SetFont(font);
    gBoard->Add(m_btnLowLeft, 0, wxALL | wxEXPAND, 5);

    m_btnLowMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnLowMid->SetFont(font);
    gBoard->Add(m_btnLowMid, 0, wxALL | wxEXPAND, 5);

    m_btnLowRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
    m_btnLowRight->SetFont(font);
    gBoard->Add(m_btnLowRight, 0, wxALL | wxEXPAND, 5);

    this->SetSizer(gBoard);
    this->Layout();

    m_StatusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

    this->Center(wxBOTH);




    Bind(wxEVT_MENU, &MainFrame::OnNewGame, this, ID_NewGame); //Bind vai associar o evento menu
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

    m_btnUpLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpLeftClick), NULL, this);
    m_btnUpMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpMidClick), NULL, this);
    m_btnUpRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnUpRightClick), NULL, this);

    m_btnMidLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidLeftClick), NULL, this);
    m_btnMidMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidMidClick), NULL, this);
    m_btnMidRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidRightClick), NULL, this);

    m_btnLowLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowLeftClick), NULL, this);
    m_btnLowMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowMidClick), NULL, this);
    m_btnLowRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowRightClick), NULL, this);


    //Bind(wxEVT_BUTTON, MainFrame::OnBtnUpMidClick, this, wxEVT_COMMAND_BUTTON_CLICKED);
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

void MainFrame::OnBtnUpLeftClick(wxCommandEvent& event){
    wxMessageBox("Botão 1", "Botão 1", wxOK | wxICON_INFORMATION);
}; 
void MainFrame::OnBtnUpMidClick(wxCommandEvent& event){
    wxMessageBox("Botão 2", "Botão 2", wxOK | wxICON_INFORMATION);
};
void MainFrame::OnBtnUpRightClick(wxCommandEvent& event){
    wxMessageBox("Botão 3", "Botão 3", wxOK | wxICON_INFORMATION);
};
void MainFrame::OnBtnMidLeftClick(wxCommandEvent& event){
    wxMessageBox("Botão 4", "Botão 4", wxOK | wxICON_INFORMATION);
};
void MainFrame::OnBtnMidMidClick(wxCommandEvent& event){
    wxMessageBox("Botão 5", "Botão 5", wxOK | wxICON_INFORMATION);
};
void MainFrame::OnBtnMidRightClick(wxCommandEvent& event){
    wxMessageBox("Botão 6", "Botão 6", wxOK | wxICON_INFORMATION);
};
void MainFrame::OnBtnLowLeftClick(wxCommandEvent& event){
    wxMessageBox("Botão 7", "Botão 7", wxOK | wxICON_INFORMATION);
};
void MainFrame::OnBtnLowMidClick(wxCommandEvent& event){
    wxMessageBox("Botão 8", "Botão 8", wxOK | wxICON_INFORMATION);
};
void MainFrame::OnBtnLowRightClick(wxCommandEvent& event){
    wxMessageBox("Botão 9", "Botão 9", wxOK | wxICON_INFORMATION);
};