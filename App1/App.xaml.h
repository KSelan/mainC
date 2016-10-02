//
// App.xaml.h
// Declaration de la classe App.
//

#pragma once

#include "App.g.h"

namespace App1
{
	/// <summary>
	/// Fournit un comportement specifique à l'application afin de completer la classe Application par defaut.
	/// </summary>
	ref class App sealed
	{
	protected:
		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) override;

	internal:
		App();

	private:
		void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);
		void OnNavigationFailed(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs ^e);
	};
}
