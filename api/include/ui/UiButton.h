
#ifndef API_UI_UIBUTTON_H_
#define API_UI_UIBUTTON_H_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>

class UiButton : public sf::Drawable, public sf::Transformable
{

private:
	sf::RectangleShape background_;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	UiButton();
	void HandleEvent(const sf::Event& event);

};

#endif // API_UI_UIBUTTON_H_

