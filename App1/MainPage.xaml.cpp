//
// MainPage.xaml.cpp
// Implementation de la classe MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "Commande.h"
#include <vector>
#include <thread>
#include "vue0.xaml.h"
#include <windows.h>

#include "point.h"

//#include "stdAfx.h"

Platform::String^ convertToWinString(std::stringstream & s)
{
	std::string s_str(s.str());
	std::wstring wid_str = std::wstring(s_str.begin(), s_str.end());
	const wchar_t* w_char = wid_str.c_str();
	return ref new Platform::String(w_char);
}

Platform::String^ convertToWinString2(std::string & s)
{
	std::wstring wid_str = std::wstring(s.begin(), s.end());
	const wchar_t* w_char = wid_str.c_str();
	return ref new Platform::String(w_char);
}

std::string convert(Platform::String ^ s)
{
	std::wstring fooW(s->Begin());
	std::string ret(fooW.begin(),fooW.end());
	return ret;
}

using namespace App1;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// Pour plus d'informations sur le modèle d'element Page vierge, consultez la page http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

std::vector<CommandeSimple*> commandes;


MainPage::~MainPage()
{
	for (std::vector<CommandeSimple*>::iterator it = commandes.begin(); it != commandes.end(); ++it)
	{
		delete(*it);
	}
}

void foo2(ProgressBar ^ bar)
{
	for (int i = 0; i < 101; i++)
	{
		//Sleep(100);
		bar->Value = i;
	}
}

bool sortCommande(CommandeSimple * c1, CommandeSimple * c2)
{
	return c1->getNom() < c2->getNom();
}

MainPage::MainPage()
{
	InitializeComponent();

	this->comboBox->Items->Clear();
	commandes.push_back(new CommandeHanoi());
	commandes.push_back(new CommandeGraph());
	commandes.push_back(new CommandeHeritage());
	commandes.push_back(new CommandeConstTest());
	commandes.push_back(new CommandeDiamant());
	commandes.push_back(new CommandeHeritageMultiple());
	commandes.push_back(new CommandeTemplate());
	commandes.push_back(new CommandeThread());
	commandes.push_back(new CommandeArbre());
	commandes.push_back(new CommandeTri());
	commandes.push_back(new CommandeException());
	commandes.push_back(new CommandeFoncteur());
	commandes.push_back(new CommandeLambda());
	commandes.push_back(new CommandePredicat());
	commandes.push_back(new CommandeReference());
	commandes.push_back(new CommandeSharedPointer());
	commandes.push_back(new CommandeAutoPointer());
	commandes.push_back(new CommandeDestructeur());
	commandes.push_back(new CommandeDeFriend());
	commandes.push_back(new CommandeTemplateTemplate());
	commandes.push_back(new CommandeVariaticFunction());
	commandes.push_back(new CommandeSurchargeOperateur());
	commandes.push_back(new CommandeExport());
	commandes.push_back(new CommandeNonCopiable());
	commandes.push_back(new CommandeSingleton());
	commandes.push_back(new CommandeSingletonThreadSafe());
	commandes.push_back(new CommandeInterpreteur());
	commandes.push_back(new CommandeLister());

	std::sort(commandes.begin(), commandes.end(), sortCommande);


	for (std::vector<CommandeSimple*>::iterator it = commandes.begin(); it != commandes.end(); ++it)
	{
		//commandes[std::string("Hanoi")] = 
		this->comboBox->Items->Append(convertToWinString2((*it)->getNom()));
		(*it)->setSortie(this->textBox);
	}

	foo2(this->ProgressBar0);

}

void foo(int i)
{
	return;
}

//#pragma warning(disable:4996)

#include <sstream>



void App1::MainPage::button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	volatile int i = 1;
	i++;
	foo(i);

	this->ProgressBar0->Minimum = 0;
	this->ProgressBar0->Maximum = 100;

	//foo2(this->ProgressBar0);

	//std::thread th(foo2, this->ProgressBar0);
	//th.join();

	//int i = 5;
	//this->comboBox->Items->Size(i);
	//Platform::String ^ command = this->comboBox->SelectedItem;
	//Platform::String ^ command = this->comboBox->Name;
	Platform::String ^ nomCommande = this->comboBox->SelectedItem->ToString();
	for (std::vector<CommandeSimple*>::iterator it = commandes.begin(); it != commandes.end(); ++it)
	{
		if (convert(nomCommande) == (*it)->getNom())
		{
			(*it)->executer();
		}
	}

	/*
	this->textBlock->Text = "start";
	std::string myText("hello");
	//myText.
	//wchar_t msg[1024];
	//strcpy((char*)msg, myText.c_str());
	std::wstringstream wss;
	wss << myText.c_str();

	std::string s_str = myText;
	std::wstring wid_str = std::wstring(s_str.begin(), s_str.end());
	const wchar_t* w_char = wid_str.c_str();
	Platform::String^ p_string = ref new Platform::String(w_char);

	this->textBlock1->Text = p_string;*/

	//this->comboBox->Items->Append("value");
	//this->comboBox->Items->Append("value1");
	//this->comboBox->Items->Append("value2");

	//Platform::String^ p_string =
	//this->comboBox->SelectedItem;
	vue0^ vue1 =  ref new vue0();
	vue1->ApplyTemplate();
	Popup^ p0 = ref new Popup();
	vue1->UpdateLayout();
	//vue1->TryStartDirectManipulation(true);
	//vue1->
	//vue1->N
//vue1->ShowAsync();	//vue1.Set
	//vue->

}
