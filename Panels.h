#pragma once

// Fix compilation.
#define __WXMSW__
#define WXUSINGDLL
// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

// Holds data about the video.
class VideoData {
public:
    std::string name, game, ratio, filepath;
    // Constructs data.
    VideoData(std::string name, std::string game, std::string ratio, std::string filepath);
    // Gets username of player in video.
    std::string getName();
    // Gets the name of the game in video.
    std::string getGame();
    // Gets the aspect ratio of the game in the video.
    std::string getRatio();
    // Gets the filepath where the video is located.
    std::string getPath();
};

// Input frame.
class InputPanel : public wxPanel {
public:
    InputPanel(wxWindow* parent);
    // Player, game, aspect ratio information.
    wxBoxSizer* PlayerDataBox;
    // Choose video button.
    wxButton* ChooseVideoButton;
    // Choose game dropdown.
    wxChoice* ChooseGameDropDown;
    // Choose aspect ratio.
    wxChoice* ChooseRatioDropDown;
    // Username input.
    wxTextCtrl* UserNameBox;
    // Process video button.
    wxButton* ProcessVideoButton;
    // Filepath as string.
    wxString VideoFilePath;
    // Game name.
    wxString GameName;
    // Aspect ratio.
    wxString AspectRatio;
    // User name.
    wxString UserName;
    // All games.
    wxArrayString games;
    // All aspect ratios.
    wxArrayString ratios;
    // Handles open file dialog.
    void OnChooseVideo(wxCommandEvent& event);
    // Handles processing video.
    void OnProcessVideo(wxCommandEvent& event);

};


// Event table enum.
enum {
    BUTTON_ChooseVideo = 1,
    BUTTON_ProcessVideo = 2,
    TEXTBOX_UserName = 3,
    DROPDOWN_ChooseGame = 4,
    DROPDOWN_ChooseAspectRatio = 5
};

