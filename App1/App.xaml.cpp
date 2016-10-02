//
// App.xaml.cpp
// Implementation de la classe App.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace App1;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

/// <summary>
/// Initialise l'objet d'application de singleton.  Il s'agit de la première ligne du code cree
/// à être executee. Elle correspond donc à l'equivalent logique de main() ou WinMain().
/// </summary>
App::App()
{
	InitializeComponent();
	Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// Appele lorsque l'application est lancee normalement par l'utilisateur final.	D'autres points d'entree
/// seront utilises par exemple au moment du lancement de l'application pour l'ouverture d'un fichier specifique.
/// </summary>
/// <param name="e">Details concernant la requête et le processus de lancement.</param>
void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e)
{

#if _DEBUG
		// Affichez des informations de profilage graphique lors du debogage.
		if (IsDebuggerPresent())
		{
			// Afficher les compteurs de frequence des trames actuels
			 DebugSettings->EnableFrameRateCounter = true;
		}
#endif

	auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);

	// Ne repetez pas l'initialisation de l'application lorsque la fenêtre comporte dejà du contenu,
	// assurez-vous juste que la fenêtre est active
	if (rootFrame == nullptr)
	{
		// Cree un frame qui joue le rôle de contexte de navigation et l'associe à
		// une cle SuspensionManager
		rootFrame = ref new Frame();

		rootFrame->NavigationFailed += ref new Windows::UI::Xaml::Navigation::NavigationFailedEventHandler(this, &App::OnNavigationFailed);

		if (e->PreviousExecutionState == ApplicationExecutionState::Terminated)
		{
			// TODO: restaurez l'etat de la session enregistree uniquement lorsque cela est necessaire, en planifiant
			// les etapes de lancement finales une fois la restauration terminee

		}

		if (rootFrame->Content == nullptr)
		{
			// Quand la pile de navigation n'est pas restauree, accedez à la première page,
			// puis configurez la nouvelle page en transmettant les informations requises en tant que
			// paramètre
			rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
		}
		// Placez le frame dans la fenêtre active
		Window::Current->Content = rootFrame;
		// Verifiez que la fenêtre actuelle est active
		Window::Current->Activate();
	}
	else
	{
		if (rootFrame->Content == nullptr)
		{
			// Quand la pile de navigation n'est pas restauree, accedez à la première page,
			// puis configurez la nouvelle page en transmettant les informations requises en tant que
			// paramètre
			rootFrame->Navigate(TypeName(MainPage::typeid), e->Arguments);
		}
		// Verifiez que la fenêtre actuelle est active
		Window::Current->Activate();
	}
}

/// <summary>
/// Appele lorsque l'execution de l'application est suspendue.	L'etat de l'application est enregistre
/// sans savoir si l'application pourra se fermer ou reprendre sans endommager
/// le contenu de la memoire.
/// </summary>
/// <param name="sender">Source de la requête de suspension.</param>
/// <param name="e">Details de la requête de suspension.</param>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
	(void) sender;	// Paramètre non utilise
	(void) e;	// Paramètre non utilise

	//TODO: enregistrez l'etat de l'application et arrêtez toute activite en arrière-plan
}

/// <summary>
/// Appele lorsque la navigation vers une page donnee echoue
/// </summary>
/// <param name="sender">Frame à l'origine de l'echec de navigation.</param>
/// <param name="e">Details relatifs à l'echec de navigation</param>
void App::OnNavigationFailed(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs ^e)
{
	throw ref new FailureException("Failed to load Page " + e->SourcePageType.Name);
}