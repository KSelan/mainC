//
// MainPage.xaml.h
// Declaration de la classe MainPage.
//

#pragma once

#include "MainPage.g.h"

namespace App1
{
	/// <summary>
	/// Une page vide peut être utilisee seule ou constituer une page de destination au sein d'un frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
		
	private:
		~MainPage();
		void button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
