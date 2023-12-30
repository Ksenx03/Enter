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
	/// Сводка для Sem6
	/// </summary>
	public ref class Sem6 : public System::Windows::Forms::Form
	{
	public:
		Sem6(void)
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
		~Sem6()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelSem6;
	private: System::Windows::Forms::DataGridView^ dataGridView7;
	private: System::Windows::Forms::Panel^ panelSem6Buttons;
	private: System::Windows::Forms::Button^ buttonSave6;
	private: System::Windows::Forms::Button^ buttonClear6;
	private: System::Windows::Forms::Button^ buttonCount6;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		void InitializeDataGridView()
		{
			dataGridView7->AutoGenerateColumns = false;
			dataGridView7->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			DataGridViewTextBoxColumn^ subjectColumn = gcnew DataGridViewTextBoxColumn();
			subjectColumn->Name = "Subject";
			subjectColumn->HeaderText = "Предмет";
			dataGridView7->Columns->Add(subjectColumn);

			array<String^>^ subjects = { "Identyfikacja systemow",
				"Praktyka zawodowa",
				"Projekt przejsciowy",
				"Systemy czasu rzeczywistego",
				"Dodatkowy przedmiot",
				"Srednia ocena"
			};

			dataGridView7->RowCount = subjects->Length;


			for (int i = 0; i < subjects->Length; ++i)
			{
				dataGridView7->Rows[i]->Cells["Subject"]->Value = subjects[i];
			}

			DataGridViewTextBoxColumn^ typeColumn = gcnew DataGridViewTextBoxColumn();
			typeColumn->Name = "Type";
			typeColumn->HeaderText = "Тип";
			dataGridView7->Columns->Add(typeColumn);

			array<String^>^ types = { "E",
				"E",
				"Z",
			};

			for (int i = 0; i < types->Length; ++i)
			{
				dataGridView7->Rows[i]->Cells["Type"]->Value = types[i];
			}

			dataGridView7->Columns["Subject"]->ReadOnly = true;
			dataGridView7->Columns["Type"]->ReadOnly = true;


			DataGridViewTextBoxColumn^ gradeColumn = gcnew DataGridViewTextBoxColumn();
			gradeColumn->Name = "Grade";
			gradeColumn->HeaderText = "Оценка";
			gradeColumn->ValueType = Object::typeid;
			dataGridView7->Columns->Add(gradeColumn);

			dataGridView7->RowHeadersVisible = false;

			// Добавление DataGridView в panelGrid
			panelSem6->Controls->Add(dataGridView7);

			subjectColumn->Width = 150;
			typeColumn->Width = 70;
			gradeColumn->Width = 70;

		}

		void LoadDataFromFile() {
			if (File::Exists("grades6.txt")) {
				array<String^>^ lines = File::ReadAllLines("grades6.txt");
				int rowCount = Math::Min(lines->Length, dataGridView7->Rows->Count);

				for (int i = 0; i < rowCount; i++) {
					dataGridView7->Rows[i]->Cells["Grade"]->Value = lines[i];
				}
			}
		}

		void CalculateAverageGrade() {
			double sum = 0.0;
			double count = 0.0;

			for (int i = 0; i < dataGridView7->Rows->Count - 1; ++i) {
				if (dataGridView7->Rows[i]->Cells[2]->Value != nullptr) {
					String^ value = dataGridView7->Rows[i]->Cells[2]->Value->ToString();
					double number;

					if (Double::TryParse(value, number)) {
						sum += number;
						count++;
					}
				}
			}

			if (count > 0) {
				double average = sum / count;
				dataGridView7->Rows[dataGridView7->Rows->Count - 1]->Cells[2]->Value = average.ToString("F2");
			}
			else {
				dataGridView7->Rows[dataGridView7->Rows->Count - 1]->Cells[2]->Value = "Нет данных";
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelSem6 = (gcnew System::Windows::Forms::Panel());
			this->panelSem6Buttons = (gcnew System::Windows::Forms::Panel());
			this->dataGridView7 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonSave6 = (gcnew System::Windows::Forms::Button());
			this->buttonCount6 = (gcnew System::Windows::Forms::Button());
			this->buttonClear6 = (gcnew System::Windows::Forms::Button());
			this->panelSem6->SuspendLayout();
			this->panelSem6Buttons->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView7))->BeginInit();
			this->SuspendLayout();
			// 
			// panelSem6
			// 
			this->panelSem6->Controls->Add(this->dataGridView7);
			this->panelSem6->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSem6->Location = System::Drawing::Point(0, 0);
			this->panelSem6->Name = L"panelSem6";
			this->panelSem6->Size = System::Drawing::Size(274, 232);
			this->panelSem6->TabIndex = 0;
			// 
			// panelSem6Buttons
			// 
			this->panelSem6Buttons->Controls->Add(this->buttonClear6);
			this->panelSem6Buttons->Controls->Add(this->buttonCount6);
			this->panelSem6Buttons->Controls->Add(this->buttonSave6);
			this->panelSem6Buttons->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelSem6Buttons->Location = System::Drawing::Point(274, 0);
			this->panelSem6Buttons->Name = L"panelSem6Buttons";
			this->panelSem6Buttons->Size = System::Drawing::Size(106, 232);
			this->panelSem6Buttons->TabIndex = 1;
			// 
			// dataGridView7
			// 
			this->dataGridView7->BackgroundColor = System::Drawing::Color::PaleTurquoise;
			this->dataGridView7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView7->Location = System::Drawing::Point(0, 0);
			this->dataGridView7->Name = L"dataGridView7";
			this->dataGridView7->Size = System::Drawing::Size(274, 232);
			this->dataGridView7->TabIndex = 0;
			// 
			// buttonSave6
			// 
			this->buttonSave6->BackColor = System::Drawing::Color::Cyan;
			this->buttonSave6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonSave6->Location = System::Drawing::Point(0, 195);
			this->buttonSave6->Name = L"buttonSave6";
			this->buttonSave6->Size = System::Drawing::Size(106, 37);
			this->buttonSave6->TabIndex = 0;
			this->buttonSave6->Text = L"Сохранить изменения";
			this->buttonSave6->UseVisualStyleBackColor = false;
			// 
			// buttonCount6
			// 
			this->buttonCount6->BackColor = System::Drawing::Color::Cyan;
			this->buttonCount6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonCount6->Location = System::Drawing::Point(0, 158);
			this->buttonCount6->Name = L"buttonCount6";
			this->buttonCount6->Size = System::Drawing::Size(106, 37);
			this->buttonCount6->TabIndex = 1;
			this->buttonCount6->Text = L"Рассчитать среднее";
			this->buttonCount6->UseVisualStyleBackColor = false;
			// 
			// buttonClear6
			// 
			this->buttonClear6->BackColor = System::Drawing::Color::Cyan;
			this->buttonClear6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonClear6->Location = System::Drawing::Point(0, 121);
			this->buttonClear6->Name = L"buttonClear6";
			this->buttonClear6->Size = System::Drawing::Size(106, 37);
			this->buttonClear6->TabIndex = 2;
			this->buttonClear6->Text = L"Очистить";
			this->buttonClear6->UseVisualStyleBackColor = false;
			// 
			// Sem6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PaleTurquoise;
			this->ClientSize = System::Drawing::Size(380, 232);
			this->Controls->Add(this->panelSem6Buttons);
			this->Controls->Add(this->panelSem6);
			this->Name = L"Sem6";
			this->Text = L"Sem6";
			this->Load += gcnew System::EventHandler(this, &Sem6::Sem6_Load);
			this->panelSem6->ResumeLayout(false);
			this->panelSem6Buttons->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView7))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Sem6_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonSave3_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamWriter^ sw = gcnew StreamWriter("grades6.txt");

		try {
			for (int i = 0; i < dataGridView7->Rows->Count; i++) {
				String^ grade = dataGridView7->Rows[i]->Cells["Grade"]->Value ? dataGridView7->Rows[i]->Cells["Grade"]->Value->ToString() : "";

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
	for each (DataGridViewRow ^ row in dataGridView7->Rows) {
		row->Cells["Grade"]->Value = ""; // Установка пустого значения для третьего столбца
	}

	// Очистка текстового файла
	System::IO::File::WriteAllText("data.txt", "");
}
};
}
