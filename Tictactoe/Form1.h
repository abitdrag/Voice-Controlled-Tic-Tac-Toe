#pragma once

#include "hmm_connection.h"
#include "game.h"

namespace Tictactoe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnStart;
	protected: 
	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::Button^  btn1;
	private: System::Windows::Forms::Button^  btn4;
	private: System::Windows::Forms::Button^  btn7;



	private: System::Windows::Forms::Button^  btn2;
	private: System::Windows::Forms::Button^  btn5;
	private: System::Windows::Forms::Button^  btn8;



	private: System::Windows::Forms::Button^  btn3;
	private: System::Windows::Forms::Button^  btn6;
	private: System::Windows::Forms::Button^  btn9;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnRecord;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::Button^  btnQuit;
	private: System::Windows::Forms::Label^  lblPlayername;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnRecord = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->btnQuit = (gcnew System::Windows::Forms::Button());
			this->lblPlayername = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnStart->Location = System::Drawing::Point(358, 166);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(135, 70);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnExit->Location = System::Drawing::Point(358, 261);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(135, 70);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Form1::btnExit_Click);
			// 
			// btn1
			// 
			this->btn1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			// this->btn1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
			this->btn1->Location = System::Drawing::Point(0, 1);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(269, 181);
			this->btn1->TabIndex = 2;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = false;
			this->btn1->Visible = false;
			// 
			// btn4
			// 
			this->btn4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn4->Location = System::Drawing::Point(0, 175);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(269, 181);
			this->btn4->TabIndex = 3;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = false;
			this->btn4->Visible = false;
			// 
			// btn7
			// 
			this->btn7->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn7->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn7->Location = System::Drawing::Point(0, 350);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(269, 181);
			this->btn7->TabIndex = 4;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = false;
			this->btn7->Visible = false;
			// 
			// btn2
			// 
			this->btn2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			// this->btn2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
			this->btn2->Location = System::Drawing::Point(266, 1);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(269, 181);
			this->btn2->TabIndex = 5;
			this->btn2->Text = L"2";
			this->btn2->UseMnemonic = false;
			this->btn2->UseVisualStyleBackColor = false;
			this->btn2->Visible = false;
			// 
			// btn5
			// 
			this->btn5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn5->Location = System::Drawing::Point(266, 175);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(269, 181);
			this->btn5->TabIndex = 6;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = false;
			this->btn5->Visible = false;
			// 
			// btn8
			// 
			this->btn8->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn8->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn8->Location = System::Drawing::Point(266, 350);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(269, 181);
			this->btn8->TabIndex = 7;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = false;
			this->btn8->Visible = false;
			// 
			// btn3
			// 
			this->btn3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			// this->btn3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			this->btn3->Location = System::Drawing::Point(532, 1);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(269, 181);
			this->btn3->TabIndex = 8;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = false;
			this->btn3->Visible = false;
			// 
			// btn6
			// 
			this->btn6->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn6->Location = System::Drawing::Point(532, 175);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(269, 181);
			this->btn6->TabIndex = 9;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = false;
			this->btn6->Visible = false;
			// 
			// btn9
			// 
			this->btn9->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn9->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn9->Location = System::Drawing::Point(532, 350);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(269, 181);
			this->btn9->TabIndex = 10;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = false;
			this->btn9->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(807, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Logs:";
			this->label1->Visible = false;
			// 
			// btnRecord
			// 
			this->btnRecord->Location = System::Drawing::Point(807, 39);
			this->btnRecord->Name = L"btnRecord";
			this->btnRecord->Size = System::Drawing::Size(75, 23);
			this->btnRecord->TabIndex = 12;
			this->btnRecord->Text = L"Record";
			this->btnRecord->UseVisualStyleBackColor = true;
			this->btnRecord->Visible = false;
			this->btnRecord->Click += gcnew System::EventHandler(this, &Form1::btnRecord_Click);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(914, 39);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 13;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Visible = false;
			this->btnReset->Click += gcnew System::EventHandler(this, &Form1::btnReset_Click);
			// 
			// btnQuit
			// 
			this->btnQuit->Location = System::Drawing::Point(1021, 39);
			this->btnQuit->Name = L"btnQuit";
			this->btnQuit->Size = System::Drawing::Size(75, 23);
			this->btnQuit->TabIndex = 14;
			this->btnQuit->Text = L"Quit";
			this->btnQuit->UseVisualStyleBackColor = true;
			this->btnQuit->Visible = false;
			this->btnQuit->Click += gcnew System::EventHandler(this, &Form1::btnQuit_Click);
			// 
			// lblPlayername
			// 
			this->lblPlayername->AutoSize = true;
			this->lblPlayername->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblPlayername->Location = System::Drawing::Point(810, 13);
			this->lblPlayername->Name = L"lblPlayername";
			this->lblPlayername->Size = System::Drawing::Size(80, 13);
			this->lblPlayername->TabIndex = 15;
			this->lblPlayername->Text = L"Player: CIRCLE";
			this->lblPlayername->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1108, 569);
			this->Controls->Add(this->lblPlayername);
			this->Controls->Add(this->btnQuit);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnRecord);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->btnExit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
			 // This function is called when start button is calicked
			 this->btn1->Visible = true;
			 this->btn2->Visible = true;
			 this->btn3->Visible = true;
			 this->btn4->Visible = true;
			 this->btn5->Visible = true;
			 this->btn6->Visible = true;
			 this->btn7->Visible = true;			 
			 this->btn8->Visible = true;
			 this->btn9->Visible = true;
			 this->label1->Visible = true;
			 this->btnReset->Visible = true;
			 this->btnQuit->Visible = true;
			 this->btnRecord->Visible = true;
			 this->btnStart->Visible = false;
			 this->btnExit->Visible = false;
			 this->lblPlayername->Visible = true;
			 // char c = initialize_hmm();
			 // MessageBox::Show("char " + c);
		 }
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
			 // this function is called when exit button is clicked
			 Application::Exit();
		 }
private: System::Void btnRecord_Click(System::Object^  sender, System::EventArgs^  e) {
			 // This function is called when record button is clicked
			 record();
			 // int predicted_digit = get_prediction();
			 int predicted_digit = get_prediction_random();
			 int mark_result = mark_on_game(predicted_digit);
			 if(mark_result == 0){
				 // invalid move
				 // String^ s = "Invalid move. Please try again!";
				 // MessageBox::Show(s);
				 
				 while(mark_result == 0){
					 predicted_digit = get_prediction_random();
					 mark_result = mark_on_game(predicted_digit);
				 }
			 }
			 // else{
			 
				 // valid move
				 // String^ s = "Valid move.";
				 // MessageBox::Show(s);
				 // 1 = CIRCLE, 2 = CROSS
				 // SET THE MOVE IN DISPLAY
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
				 if(player == 2){
					 // set circle as picture
					 if(predicted_digit == 1){
						 this->btn1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
						 
					 }
					 else if(predicted_digit == 2){
						 this->btn2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
						
					 }
					 else if(predicted_digit == 3){
						 this->btn3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
						
					 }
					 else if(predicted_digit == 4){
						 this->btn4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
						 
					 }
					 else if(predicted_digit == 5){
						 this->btn5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
						 
					 }
					 else if(predicted_digit == 6){
						 this->btn6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
						
					 }
					 else if(predicted_digit == 7){
						 this->btn7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
						 
					 }
					 else if(predicted_digit == 8){
						 this->btn8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
						 
					 }
					 else if(predicted_digit == 9){
						 this->btn9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn1.Image")));
						 
					 }
				 }
				 else{
					 // set cross as picture
					 if(predicted_digit == 1){
						 this->btn1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
					 }
					 else if(predicted_digit == 2){
						 this->btn2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
					 }
					 else if(predicted_digit == 3){
						 this->btn3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
					 }
					 else if(predicted_digit == 4){
						 this->btn4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
					 }
					 else if(predicted_digit == 5){
						 this->btn5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
					 }
					 else if(predicted_digit == 6){
						 this->btn6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
					 }
					 else if(predicted_digit == 7){
						 this->btn7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
					 }
					 else if(predicted_digit == 8){
						 this->btn8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
					 }
					 else if(predicted_digit == 9){
						 this->btn9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn2.Image")));
					 }
				 }
			

				 // CHECK FOR WINNER
				 int winner_result = check_winner();
				 if(winner_result == 1){
					 // winner has been found
					 if(player == 1){
						// player 2 is winner 
						 String^ s = "Player CROSS is winner!";
						 MessageBox::Show(s);
						 // remove image from all buttons
						 this->btn1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 // reset the array and player
						 reset_game();
						 // change the name of player
						 this->lblPlayername->Text = L"Player: CIRCLE";
					 }
					 else{
						 // player 1 is winner
						 String^ s = "Player CIRCLE is winner!";
						 MessageBox::Show(s);
						 // remove image from all buttons
						 this->btn1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 this->btn9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
						 // reset the array and player
						 reset_game();
						 // change the name of player
						 this->lblPlayername->Text = L"Player: CIRCLE";
					 }
				 }
				 else if(winner_result == 0){
					 // draw
					 String^ s = "Game DRAW!";
					 MessageBox::Show(s);
				 }

				 // set the label for next player
				 if(player == 1){
					 this->lblPlayername->Text = L"Player: CIRCLE";
				 }
				 else{
					 this->lblPlayername->Text = L"Player: CROSS";
				 }
			 // }
		 }


private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
			 // this function is called when reset button is clicked
			 System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			 // remove image from all buttons
			 this->btn1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			 this->btn2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			 this->btn3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			 this->btn4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			 this->btn5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			 this->btn6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			 this->btn7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			 this->btn8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			 this->btn9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btn3.Image")));
			 // reset the array and player
			 reset_game();
			 // change the name of player
			 this->lblPlayername->Text = L"Player: CIRCLE";
		 }
private: System::Void btnQuit_Click(System::Object^  sender, System::EventArgs^  e) {
			 // This function closes the application
			 Application::Exit();
		 }
};
}

