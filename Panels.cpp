#pragma once
#include "Panels.h"
#include <opencv2\videoio.hpp>
#include "Game.h"
#include "Video.h"
#include <iostream>

// VideoData class implementation.
VideoData::VideoData(std::string name, std::string game, std::string ratio, std::string filepath) {
	this->name = name;
	this->game = game;
	this->ratio = ratio;
	this->filepath = filepath;
}

// Gets the username to look for.
std::string VideoData::getName() {
	return this->name;
}

// Gets the name of the game in the video.
std::string VideoData::getGame() {
	return this->game;
}

// Gets the aspect ratio of the video.
std::string VideoData::getRatio() {
	return this->ratio;
}

// Gets the path of the chosen video.
std::string VideoData::getPath() {
	return this->filepath;
}

// Input Panel implementation.
InputPanel::InputPanel(wxWindow* parent) 
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {
	PlayerDataBox = new wxBoxSizer(wxHORIZONTAL);
	ChooseVideoButton = new wxButton(this, BUTTON_ChooseVideo, _T("Choose Video"),
		wxDefaultPosition, wxDefaultSize, 0);
	ProcessVideoButton = new wxButton(this, BUTTON_ProcessVideo, _T("Process Video"), wxDefaultPosition, wxDefaultSize, 0);
	// Add games to dropdown.
	this->games.Add("Rainbow Six: Siege");
	// Add aspect ratios to dropdown.
	this->ratios.Add("4:3");
	UserNameBox = new wxTextCtrl(this, TEXTBOX_UserName);
	ChooseGameDropDown = new wxChoice(this, DROPDOWN_ChooseGame, wxDefaultPosition, wxDefaultSize, games);
	ChooseRatioDropDown = new wxChoice(this, DROPDOWN_ChooseAspectRatio, wxDefaultPosition, wxDefaultSize, ratios);
	PlayerDataBox->Add(UserNameBox);
	PlayerDataBox->Add(ChooseGameDropDown);
	PlayerDataBox->Add(ChooseRatioDropDown);
	PlayerDataBox->Add(ChooseVideoButton);
	PlayerDataBox->Add(ProcessVideoButton);
	SetSizerAndFit(PlayerDataBox);
}

// When choose video button is clicked.
void InputPanel::OnChooseVideo(wxCommandEvent& event) {
	std::cout << "Test" << std::endl;
	wxFileDialog* OpenDialog = new wxFileDialog(
		this, _("Choose a video to open"), wxEmptyString, wxEmptyString,
		_("Video Files|*.mp4|"),
		wxFD_OPEN, wxDefaultPosition);

	// Creates a "open file" dialog.
	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
		VideoFilePath = OpenDialog->GetPath();
		// Sets our current document to the file the user selected.
	}

	// Clean up after ourselves
	OpenDialog->Destroy();
}

// Processes the video.
void InputPanel::OnProcessVideo(wxCommandEvent& event) {
	// Update game name.
	this->GameName = this->games[ChooseGameDropDown->GetSelection()];
	// Update aspect ratio.
	this->AspectRatio = this->ratios[ChooseRatioDropDown->GetSelection()];
	// Open the video with OpenCV.
	cv::VideoCapture* cap = new cv::VideoCapture(std::string(this->VideoFilePath.mb_str()));
	Game g = Game(std::string(this->GameName.mb_str()), std::string(this->AspectRatio.mb_str()));
	// Create the game.
	// Start processing the video.
	Video::processVideo(cap, g, std::string(this->UserName.mb_str()));
}

