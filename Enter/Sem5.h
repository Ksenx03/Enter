#pragma once

namespace Enter {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Sem5
	/// </summary>
	public ref class Sem5 : public System::Windows::Forms::Form
	{
	public:
		Sem5(void)
		{
			InitializeComponent();
			InitializeDataGridView();
			LoadDataFromFile();
			CalculateAverageGrade();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Sem5()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelSem5;
	private: System::Windows::Forms::Panel^ panelSem5Buttons;
	private: System::Windows::Forms::DataGridView^ dataGridView5;
	private: System::Windows::Forms::Button^ buttonSave5;
	private: System::Windows::Forms::Button^ buttonClear5;

	private: System::Windows::Forms::Button^ buttonCount5;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		void InitializeDataGridView()
		{
			dataGridView5->AutoGenerateColumns = false;
			dataGridView5->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			DataGridViewTextBoxColumn^ subjectColumn = gcnew DataGridViewTextBoxColumn();
			subjectColumn->Name = "Subject";
			subjectColumn->HeaderText = "Предмет";
			dataGridView5->Columns->Add(subjectColumn);

			array<String^>^ subjects = { "Napedy przeksztaltnikowe",
				"Programowanie sterownikow PLC i regulatorow przemyslowych",
				"Systemy mikroprocesorowe",
				"Teoria sterowania",
				"Dodatkowy przedmiot",
				"Srednia ocena"
			};

			dataGridView5->RowCount = subjects->Length;


			for (int i = 0; i < subjects->Length; ++i)
			{
				dataGridView5->Rows[i]->Cells["Subject"]->Value = subjects[i];
			}

			DataGridViewTextBoxColumn^ typeColumn = gcnew DataGridViewTextBoxColumn();
			typeColumn->Name = "Type";
			typeColumn->HeaderText = "Тип";
			dataGridView5->Columns->Add(typeColumn);

			array<String^>^ types = { "E",
				"E",
				"Z",
			};

			for (int i = 0; i < types->Length; ++i)
			{
				dataGridView5->Rows[i]->Cells["Type"]->Value = types[i];
			}

			dataGridView5->Columns["Subject"]->ReadOnly = true;
			dataGridView5->Columns["Type"]->ReadOnly = true;


			DataGridViewTextBoxColumn^ gradeColumn = gcnew DataGridViewTextBoxColumn();
			gradeColumn->Name = "Grade";
			gradeColumn->HeaderText = "Оценка";
			gradeColumn->ValueType = Object::typeid;
			dataGridView5->Columns->Add(gradeColumn);

			dataGridView5->RowHeadersVisible = false;

			// Добавление DataGridView в panelGrid
			panelSem5->Controls->Add(dataGridView5);

			subjectColumn->Width = 150;
			typeColumn->Width = 70;
			gradeColumn->Width = 70;

		}

		void LoadDataFromFile() {
			if (File::Exists("grades5.txt")) {
				array<String^>^ lines = File::ReadAllLines("grades5.txt");
				int rowCount = Math::Min(lines->Length, dataGridView5->Rows->Count);

				for (int i = 0; i < rowCount; i++) {
					dataGridView5->Rows[i]->Cells["Grade"]->Value = lines[i];
				}
			}
		}

		void CalculateAverageGrade() {
			double sum = 0.0;
			double count = 0.0;

			for (int i = 0; i < dataGridView5->Rows->Count - 1; ++i) {
				if (dataGridView5->Rows[i]->Cells[2]->Value != nullptr) {
					String^ value = dataGridView5->Rows[i]->Cells[2]->Value->ToString();
					double number;

					if (Double::TryParse(value, number)) {
						sum += number;
						count++;
					}
				}
			}

			if (count > 0) {
				double average = sum / count;
				dataGridView5->Rows[dataGridView5->Rows->Count - 1]->Cells[2]->Value = average.ToString("F2");
			}
			else {
				dataGridView5->Rows[dataGridView5->Rows->Count - 1]->Cells[2]->Value = "Нет данных";
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelSem5 = (gcnew System::Windows::Forms::Panel());
			this->panelSem5Buttons = (gcnew System::Windows::Forms::Panel());
			this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonSave5 = (gcnew System::Windows::Forms::Button());
			this->buttonCount5 = (gcnew System::Windows::Forms::Button());
			this->buttonClear5 = (gcnew System::Windows::Forms::Button());
			this->panelSem5->SuspendLayout();
			this->panelSem5Buttons->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
			this->SuspendLayout();
			// 
			// panelSem5
			// 
			this->panelSem5->Controls->Add(this->dataGridView5);
			this->panelSem5->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSem5->Location = System::Drawing::Point(0, 0);
			this->panelSem5->Name = L"panelSem5";
			this->panelSem5->Size = System::Drawing::Size(274, 232);
			this->panelSem5->TabIndex = 0;
			// 
			// panelSem5Buttons
			// 
			this->panelSem5Buttons->Controls->Add(this->buttonClear5);
			this->panelSem5Buttons->Controls->Add(this->buttonCount5);
			this->panelSem5Buttons->Controls->Add(this->buttonSave5);
			this->panelSem5Buttons->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelSem5Buttons->Location = System::Drawing::Point(274, 0);
			this->panelSem5Buttons->Name = L"panelSem5Buttons";
			this->panelSem5Buttons->Size = System::Drawing::Size(106, 232);
			this->panelSem5Buttons->TabIndex = 1;
			// 
			// dataGridView5
			// 
			this->dataGridView5->BackgroundColor = System::Drawing::Color::MediumTurquoise;
			this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView5->Location = System::Drawing::Point(0, 0);
			this->dataGridView5->Name = L"dataGridView5";
			this->dataGridView5->Size = System::Drawing::Size(274, 232);
			this->dataGridView5->TabIndex = 0;
			// 
			// buttonSave5
			// 
			this->buttonSave5->BackColor = System::Drawing::Color::PaleTurquoise;
			this->buttonSave5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonSave5->Location = System::Drawing::Point(0, 195);
			this->buttonSave5->Name = L"buttonSave5";
			this->buttonSave5->Size = System::Drawing::Size(106, 37);
			this->buttonSave5->TabIndex = 0;
			this->buttonSave5->Text = L"Сохранить изменения";
			this->buttonSave5->UseVisualStyleBackColor = false;
			// 
			// buttonCount5
			// 
			this->buttonCount5->BackColor = System::Drawing::Color::PaleTurquoise;
			this->buttonCount5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonCount5->Location = System::Drawing::Point(0, 158);
			this->buttonCount5->Name = L"buttonCount5";
			this->buttonCount5->Size = System::Drawing::Size(106, 37);
			this->buttonCount5->TabIndex = 1;
			this->buttonCount5->Text = L"Рассчитать среднее";
			this->buttonCount5->UseVisualStyleBackColor = false;
			// 
			// buttonClear5
			// 
			this->buttonClear5->BackColor = System::Drawing::Color::PaleTurquoise;
			this->buttonClear5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonClear5->Location = System::Drawing::Point(0, 121);
			this->buttonClear5->Name = L"buttonClear5";
			this->buttonClear5->Size = System::Drawing::Size(106, 37);
			this->buttonClear5->TabIndex = 2;
			this->buttonClear5->Text = L"Очистить";
			this->buttonClear5->UseVisualStyleBackColor = false;
			// 
			// Sem5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MediumTurquoise;
			this->ClientSize = System::Drawing::Size(380, 232);
			this->Controls->Add(this->panelSem5Buttons);
			this->Controls->Add(this->panelSem5);
			this->Name = L"Sem5";
			this->Text = L"Sem5";
			this->Load += gcnew System::EventHandler(this, &Sem5::Sem5_Load);
			this->panelSem5->ResumeLayout(false);
			this->panelSem5Buttons->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Sem5_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonSave3_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamWriter^ sw = gcnew StreamWriter("grades5.txt");

		try {
			for (int i = 0; i < dataGridView5->Rows->Count; i++) {
				String^ grade = dataGridView5->Rows[i]->Cells["Grade"]->Value ? dataGridView5->Rows[i]->Cells["Grade"]->Value->ToString() : "";

				// Запись значения 'grade' в файл
				sw->WriteLine(grade);
			}

			// Показать сообщение об успешном сохранении
			MessageBox::Show("Сохранено успешно!");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка при сохранении: " + ex->Message);
		}
		finally {
			if (sw != nullptr) {
				sw->Close();
			}
		}
	}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	CalculateAverageGrade();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	for each (DataGridViewRow ^ row in dataGridView5->Rows) {
		row->Cells["Grade"]->Value = ""; // Установка пустого значения для третьего столбца
	}

	// Очистка текстового файла
	System::IO::File::WriteAllText("data.txt", "");
}
};
}
