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
	/// Сводка для Sem7
	/// </summary>
	public ref class Sem7 : public System::Windows::Forms::Form
	{
	public:
		Sem7(void)
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
		~Sem7()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelSem7;
	private: System::Windows::Forms::DataGridView^ dataGridView7;
	private: System::Windows::Forms::Panel^ panelSem7Buttons;
	private: System::Windows::Forms::Button^ buttonClear7;
	private: System::Windows::Forms::Button^ buttonCount7;
	private: System::Windows::Forms::Button^ buttonSave7;
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

			array<String^>^ subjects = { "Przygotowanie do badan naukowych",
				"Przygotowanie pracy dyplomowej",
				"Seminarium dyplomowe",
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
			panelSem7->Controls->Add(dataGridView7);

			subjectColumn->Width = 150;
			typeColumn->Width = 70;
			gradeColumn->Width = 70;

		}

		void LoadDataFromFile() {
			if (File::Exists("grades7.txt")) {
				array<String^>^ lines = File::ReadAllLines("grades7.txt");
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
			this->panelSem7 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView7 = (gcnew System::Windows::Forms::DataGridView());
			this->panelSem7Buttons = (gcnew System::Windows::Forms::Panel());
			this->buttonClear7 = (gcnew System::Windows::Forms::Button());
			this->buttonCount7 = (gcnew System::Windows::Forms::Button());
			this->buttonSave7 = (gcnew System::Windows::Forms::Button());
			this->panelSem7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView7))->BeginInit();
			this->panelSem7Buttons->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelSem7
			// 
			this->panelSem7->Controls->Add(this->dataGridView7);
			this->panelSem7->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSem7->Location = System::Drawing::Point(0, 0);
			this->panelSem7->Name = L"panelSem7";
			this->panelSem7->Size = System::Drawing::Size(274, 232);
			this->panelSem7->TabIndex = 0;
			// 
			// dataGridView7
			// 
			this->dataGridView7->BackgroundColor = System::Drawing::Color::Cyan;
			this->dataGridView7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView7->Location = System::Drawing::Point(0, 0);
			this->dataGridView7->Name = L"dataGridView7";
			this->dataGridView7->Size = System::Drawing::Size(274, 232);
			this->dataGridView7->TabIndex = 0;
			// 
			// panelSem7Buttons
			// 
			this->panelSem7Buttons->Controls->Add(this->buttonClear7);
			this->panelSem7Buttons->Controls->Add(this->buttonCount7);
			this->panelSem7Buttons->Controls->Add(this->buttonSave7);
			this->panelSem7Buttons->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelSem7Buttons->Location = System::Drawing::Point(274, 0);
			this->panelSem7Buttons->Name = L"panelSem7Buttons";
			this->panelSem7Buttons->Size = System::Drawing::Size(106, 232);
			this->panelSem7Buttons->TabIndex = 1;
			// 
			// buttonClear7
			// 
			this->buttonClear7->BackColor = System::Drawing::Color::Turquoise;
			this->buttonClear7->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonClear7->Location = System::Drawing::Point(0, 121);
			this->buttonClear7->Name = L"buttonClear7";
			this->buttonClear7->Size = System::Drawing::Size(106, 37);
			this->buttonClear7->TabIndex = 2;
			this->buttonClear7->Text = L"Очистить";
			this->buttonClear7->UseVisualStyleBackColor = false;
			// 
			// buttonCount7
			// 
			this->buttonCount7->BackColor = System::Drawing::Color::Turquoise;
			this->buttonCount7->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonCount7->Location = System::Drawing::Point(0, 158);
			this->buttonCount7->Name = L"buttonCount7";
			this->buttonCount7->Size = System::Drawing::Size(106, 37);
			this->buttonCount7->TabIndex = 1;
			this->buttonCount7->Text = L"Рассчитать среднее";
			this->buttonCount7->UseVisualStyleBackColor = false;
			// 
			// buttonSave7
			// 
			this->buttonSave7->BackColor = System::Drawing::Color::Turquoise;
			this->buttonSave7->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonSave7->Location = System::Drawing::Point(0, 195);
			this->buttonSave7->Name = L"buttonSave7";
			this->buttonSave7->Size = System::Drawing::Size(106, 37);
			this->buttonSave7->TabIndex = 0;
			this->buttonSave7->Text = L"Сохранить изменения";
			this->buttonSave7->UseVisualStyleBackColor = false;
			// 
			// Sem7
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Cyan;
			this->ClientSize = System::Drawing::Size(380, 232);
			this->Controls->Add(this->panelSem7Buttons);
			this->Controls->Add(this->panelSem7);
			this->Name = L"Sem7";
			this->Text = L"Sem7";
			this->Load += gcnew System::EventHandler(this, &Sem7::Sem7_Load);
			this->panelSem7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView7))->EndInit();
			this->panelSem7Buttons->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Sem7_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonSave3_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamWriter^ sw = gcnew StreamWriter("grades7.txt");

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
