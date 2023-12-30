#pragma once

#include <windows.h>

namespace Enter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;
	using namespace System::Globalization;



	/// <summary>
	/// —водка дл€ Library
	/// </summary>
	public ref class Library : public System::Windows::Forms::Form
	{
	public:
		Library(void)
		{
			InitializeComponent();
			InitializeDataGridView();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Library()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridViewLib;
		   DataSet^ dataSet;
	private: System::Windows::Forms::Button^ buttonSaveLib;
	private: System::Windows::Forms::Button^ buttonClearLib;
	private: System::Windows::Forms::Panel^ panelLib;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Library::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridViewLib = (gcnew System::Windows::Forms::DataGridView());
			this->buttonSaveLib = (gcnew System::Windows::Forms::Button());
			this->buttonClearLib = (gcnew System::Windows::Forms::Button());
			this->panelLib = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLib))->BeginInit();
			this->panelLib->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::DarkCyan;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(139, 311);
			this->panel1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(12, 239);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 65);
			this->label2->TabIndex = 5;
			this->label2->Text = L"poniedzialek - piatek:  \r\n9.00 - 20.00 \r\n\r\nsobota:  \r\n9.00 - 14.00 ";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(12, 203);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 26);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Piotrowo 2, \r\n61-138 Poznan\r\n";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(139, 67);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridViewLib
			// 
			this->dataGridViewLib->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewLib->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridViewLib->Location = System::Drawing::Point(0, 0);
			this->dataGridViewLib->Name = L"dataGridViewLib";
			this->dataGridViewLib->Size = System::Drawing::Size(345, 311);
			this->dataGridViewLib->TabIndex = 3;
			// 
			// buttonSaveLib
			// 
			this->buttonSaveLib->BackColor = System::Drawing::Color::DarkCyan;
			this->buttonSaveLib->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonSaveLib->Location = System::Drawing::Point(233, 276);
			this->buttonSaveLib->Name = L"buttonSaveLib";
			this->buttonSaveLib->Size = System::Drawing::Size(75, 23);
			this->buttonSaveLib->TabIndex = 4;
			this->buttonSaveLib->Text = L"Save";
			this->buttonSaveLib->UseVisualStyleBackColor = false;
			this->buttonSaveLib->Click += gcnew System::EventHandler(this, &Library::buttonSaveLib_Click);
			// 
			// buttonClearLib
			// 
			this->buttonClearLib->BackColor = System::Drawing::Color::DarkCyan;
			this->buttonClearLib->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonClearLib->Location = System::Drawing::Point(152, 276);
			this->buttonClearLib->Name = L"buttonClearLib";
			this->buttonClearLib->Size = System::Drawing::Size(75, 23);
			this->buttonClearLib->TabIndex = 5;
			this->buttonClearLib->Text = L"Clear";
			this->buttonClearLib->UseVisualStyleBackColor = false;
			this->buttonClearLib->Click += gcnew System::EventHandler(this, &Library::buttonClearLib_Click);
			// 
			// panelLib
			// 
			this->panelLib->Controls->Add(this->buttonClearLib);
			this->panelLib->Controls->Add(this->buttonSaveLib);
			this->panelLib->Controls->Add(this->dataGridViewLib);
			this->panelLib->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelLib->Location = System::Drawing::Point(139, 0);
			this->panelLib->Name = L"panelLib";
			this->panelLib->Size = System::Drawing::Size(345, 311);
			this->panelLib->TabIndex = 3;
			// 
			// Library
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(484, 311);
			this->Controls->Add(this->panelLib);
			this->Controls->Add(this->panel1);
			this->Name = L"Library";
			this->Text = L"Library";
			this->Load += gcnew System::EventHandler(this, &Library::Library_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewLib))->EndInit();
			this->panelLib->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		void InitializeDataGridView()
		{
			dataSet = gcnew DataSet("MyDataSet");
			dataGridViewLib->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewLib->Dock = DockStyle::Fill;
			DataTable^ dataTable = gcnew DataTable("MyTable");
			dataTable->Columns->Add("Book", String::typeid);  // ѕустой столбец дл€ "Book"
			dataTable->Columns->Add("Termin", String::typeid); // ѕустой столбец дл€ "Termin"
			dataSet->Tables->Add(dataTable);
			dataGridViewLib->DataSource = dataSet->Tables["MyTable"];
			dataGridViewLib->ScrollBars = System::Windows::Forms::ScrollBars::None;
			dataGridViewLib->Size = panelLib->Size;
			DataGridViewComboBoxColumn^ statusColumn = gcnew DataGridViewComboBoxColumn();
			statusColumn->HeaderText = "Status";
			statusColumn->Items->AddRange("W trakcie", "Zakonczono", "Przedluzono");
			dataGridViewLib->Columns->Add(statusColumn);
			dataGridViewLib->RowHeadersVisible = false;
		}
#pragma endregion
private: System::Void Library_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonSaveLib_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonClearLib_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
