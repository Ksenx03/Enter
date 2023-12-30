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
	/// Сводка для Sem4
	/// </summary>
	public ref class Sem4 : public System::Windows::Forms::Form
	{
	public:
		Sem4(void)
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
		~Sem4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelSem4;
	private: System::Windows::Forms::Panel^ panelSem4Buttons;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::Button^ buttonSave4;
	private: System::Windows::Forms::Button^ buttonClear4;
	private: System::Windows::Forms::Button^ buttonCount4;

	protected:

	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		void InitializeDataGridView()
		{
			dataGridView4->AutoGenerateColumns = false;
			dataGridView4->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			DataGridViewTextBoxColumn^ subjectColumn = gcnew DataGridViewTextBoxColumn();
			subjectColumn->Name = "Subject";
			subjectColumn->HeaderText = "Предмет";
			dataGridView4->Columns->Add(subjectColumn);

			array<String^>^ subjects = { "Elementy i urzadzenia automatyki",
				"Grafika inzynierska",
				"Metrologia i miernictwo techniczne",
				"Modelowanie i sterowanie robotow",
				"Sterowanie procesami ciaglymi i dyskretnymi",
				"Technika cyfrowa",
				"Jezyk obcy",
				"Dodatkowy przedmiot",
				"Srednia ocena"
			};

			dataGridView4->RowCount = subjects->Length;


			for (int i = 0; i < subjects->Length; ++i)
			{
				dataGridView4->Rows[i]->Cells["Subject"]->Value = subjects[i];
			}

			DataGridViewTextBoxColumn^ typeColumn = gcnew DataGridViewTextBoxColumn();
			typeColumn->Name = "Type";
			typeColumn->HeaderText = "Тип";
			dataGridView4->Columns->Add(typeColumn);

			array<String^>^ types = { "E",
				"E",
				"Z",
				"E",
				"Z",
				"Z",
				"Z",
				"Z",
			};

			for (int i = 0; i < types->Length; ++i)
			{
				dataGridView4->Rows[i]->Cells["Type"]->Value = types[i];
			}

			dataGridView4->Columns["Subject"]->ReadOnly = true;
			dataGridView4->Columns["Type"]->ReadOnly = true;


			DataGridViewTextBoxColumn^ gradeColumn = gcnew DataGridViewTextBoxColumn();
			gradeColumn->Name = "Grade";
			gradeColumn->HeaderText = "Оценка";
			gradeColumn->ValueType = Object::typeid;
			dataGridView4->Columns->Add(gradeColumn);

			dataGridView4->RowHeadersVisible = false;

			// Добавление DataGridView в panelGrid
			panelSem4->Controls->Add(dataGridView4);

			subjectColumn->Width = 150;
			typeColumn->Width = 70;
			gradeColumn->Width = 70;

		}

		void LoadDataFromFile() {
			if (File::Exists("grades4.txt")) {
				array<String^>^ lines = File::ReadAllLines("grades4.txt");
				int rowCount = Math::Min(lines->Length, dataGridView4->Rows->Count);

				for (int i = 0; i < rowCount; i++) {
					dataGridView4->Rows[i]->Cells["Grade"]->Value = lines[i];
				}
			}
		}

		void CalculateAverageGrade() {
			double sum = 0.0;
			double count = 0.0;

			for (int i = 0; i < dataGridView4->Rows->Count - 1; ++i) {
				if (dataGridView4->Rows[i]->Cells[2]->Value != nullptr) {
					String^ value = dataGridView4->Rows[i]->Cells[2]->Value->ToString();
					double number;

					if (Double::TryParse(value, number)) {
						sum += number;
						count++;
					}
				}
			}

			if (count > 0) {
				double average = sum / count;
				dataGridView4->Rows[dataGridView4->Rows->Count - 1]->Cells[2]->Value = average.ToString("F2");
			}
			else {
				dataGridView4->Rows[dataGridView4->Rows->Count - 1]->Cells[2]->Value = "Нет данных";
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelSem4 = (gcnew System::Windows::Forms::Panel());
			this->panelSem4Buttons = (gcnew System::Windows::Forms::Panel());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonSave4 = (gcnew System::Windows::Forms::Button());
			this->buttonCount4 = (gcnew System::Windows::Forms::Button());
			this->buttonClear4 = (gcnew System::Windows::Forms::Button());
			this->panelSem4->SuspendLayout();
			this->panelSem4Buttons->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// panelSem4
			// 
			this->panelSem4->Controls->Add(this->dataGridView4);
			this->panelSem4->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSem4->Location = System::Drawing::Point(0, 0);
			this->panelSem4->Name = L"panelSem4";
			this->panelSem4->Size = System::Drawing::Size(274, 232);
			this->panelSem4->TabIndex = 0;
			// 
			// panelSem4Buttons
			// 
			this->panelSem4Buttons->Controls->Add(this->buttonClear4);
			this->panelSem4Buttons->Controls->Add(this->buttonCount4);
			this->panelSem4Buttons->Controls->Add(this->buttonSave4);
			this->panelSem4Buttons->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelSem4Buttons->Location = System::Drawing::Point(274, 0);
			this->panelSem4Buttons->Name = L"panelSem4Buttons";
			this->panelSem4Buttons->Size = System::Drawing::Size(106, 232);
			this->panelSem4Buttons->TabIndex = 1;
			// 
			// dataGridView4
			// 
			this->dataGridView4->BackgroundColor = System::Drawing::Color::LightSeaGreen;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView4->Location = System::Drawing::Point(0, 0);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(274, 232);
			this->dataGridView4->TabIndex = 0;
			// 
			// buttonSave4
			// 
			this->buttonSave4->BackColor = System::Drawing::Color::MediumTurquoise;
			this->buttonSave4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonSave4->Location = System::Drawing::Point(0, 195);
			this->buttonSave4->Name = L"buttonSave4";
			this->buttonSave4->Size = System::Drawing::Size(106, 37);
			this->buttonSave4->TabIndex = 0;
			this->buttonSave4->Text = L"Сохранить изменения";
			this->buttonSave4->UseVisualStyleBackColor = false;
			// 
			// buttonCount4
			// 
			this->buttonCount4->BackColor = System::Drawing::Color::MediumTurquoise;
			this->buttonCount4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonCount4->Location = System::Drawing::Point(0, 158);
			this->buttonCount4->Name = L"buttonCount4";
			this->buttonCount4->Size = System::Drawing::Size(106, 37);
			this->buttonCount4->TabIndex = 1;
			this->buttonCount4->Text = L"Рассчитать среднее";
			this->buttonCount4->UseVisualStyleBackColor = false;
			// 
			// buttonClear4
			// 
			this->buttonClear4->BackColor = System::Drawing::Color::MediumTurquoise;
			this->buttonClear4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->buttonClear4->Location = System::Drawing::Point(0, 121);
			this->buttonClear4->Name = L"buttonClear4";
			this->buttonClear4->Size = System::Drawing::Size(106, 37);
			this->buttonClear4->TabIndex = 2;
			this->buttonClear4->Text = L"Очистить";
			this->buttonClear4->UseVisualStyleBackColor = false;
			// 
			// Sem4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSeaGreen;
			this->ClientSize = System::Drawing::Size(380, 232);
			this->Controls->Add(this->panelSem4Buttons);
			this->Controls->Add(this->panelSem4);
			this->Name = L"Sem4";
			this->Text = L"Sem4";
			this->Load += gcnew System::EventHandler(this, &Sem4::Sem4_Load);
			this->panelSem4->ResumeLayout(false);
			this->panelSem4Buttons->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonSave3_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamWriter^ sw = gcnew StreamWriter("grades4.txt");

		try {
			for (int i = 0; i < dataGridView4->Rows->Count; i++) {
				String^ grade = dataGridView4->Rows[i]->Cells["Grade"]->Value ? dataGridView4->Rows[i]->Cells["Grade"]->Value->ToString() : "";

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
	for each (DataGridViewRow ^ row in dataGridView4->Rows) {
		row->Cells["Grade"]->Value = ""; // Установка пустого значения для третьего столбца
	}

	// Очистка текстового файла
	System::IO::File::WriteAllText("data.txt", "");
}
	private: System::Void Sem4_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
