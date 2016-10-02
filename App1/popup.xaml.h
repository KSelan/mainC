//
// popup.xaml.h
// Déclaration de la classe popup
//

#pragma once

#include "popup.g.h"

namespace App1
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class popup sealed
	{
	public:
		popup();
	private:
		void ContentDialog_PrimaryButtonClick(Windows::UI::Xaml::Controls::ContentDialog^ sender, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs^ args);
		void ContentDialog_SecondaryButtonClick(Windows::UI::Xaml::Controls::ContentDialog^ sender, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs^ args);
	};
}
