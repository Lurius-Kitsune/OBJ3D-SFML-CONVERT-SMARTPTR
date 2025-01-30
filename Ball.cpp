#include "Ball.h"
#include "TimerManager.h"

Ball::Ball(const float _radius) : MeshActor(_radius, 30, "Ball_2")
{
    canMove = false;
	startPosition = Vector2f();
    velocity = Vector2f();
    mass = 50.0f;
    gravity = 9.81f;
    restitution = 0.85f;
    friction = 0.95f;
    groundLevel = 550.0f;

    line = VertexArray(PrimitiveType::Lines, 2);
    line[0].color = Color::Red;
    line[1].color = Color::Blue;

    lifeSpan = 3.0f;

    SetOriginAtMiddle();
}

void Ball::BeginPlay()
{
    Super::BeginPlay();

    startPosition = GetPosition();
    MakeShared<Timer<Seconds>>([&]()
    { 
        canMove = true; 
        AddForce(Vector2f(300.0f, 0.0f));

    }, seconds(2.0f), true);
}

void Ball::Tick(const float _deltaTime)
{
    Super::Tick(_deltaTime);

    LOG(Display, "X: " + to_string(line[0].position.x) + " Y: " + to_string(line[0].position.y));

    if (!canMove) return;

    // Appliquer la gravité
    const float _downVelocity = gravity * mass * _deltaTime;
    const Vector2f& _direction = Vector2f(velocity.x, velocity.y + _downVelocity);
    line[1].position = _direction; // mal recalculé
    HitInfo _info;

    if (!Raycast(GetPosition(), _direction, _downVelocity, _info))
    {
        velocity.y += _downVelocity;
        LOG(Display, "Gravity !");
    }
    else
    {
        LOG(Display, "Collision !");
    }

    // Calculer le déplacement
    const Vector2f& _displacement = velocity * _deltaTime;

    // Mettre à jour la position
    Move(_displacement);
}


void Ball::RenderMesh(RenderWindow& _window)
{
    Super::RenderMesh(_window);

    line[0].position = GetPosition();
    _window.draw(line);
}

void Ball::ApplyBounce(const Vector2f& _normal)
{
    // Pour ressortir du sol
    Move(-_normal * 0.1f);

    // Appliquer le rebond : inverser la composante normale de la vitesse
    velocity -= 2.0f * DotProduct(velocity, _normal) * _normal;

    // Réduire la vitesse en fonction du facteur de restitution
    velocity *= restitution;

    // Appliquer la friction à la composante tangentielle
    velocity.x *= friction;

    // Éviter de petites oscillations en annulant de faibles valeurs
    if (abs(velocity.x) < 1.0f)
    {
        velocity.x = 0.0f;
    }

    if (abs(velocity.y) < 1.0f)
    {
        velocity.y = 0.0f;
    }
}

void Ball::AddForce(const Vector2f _velocity)
{
    velocity += _velocity;
}