#include "DuckHuntGame.h"
#include "TimerManager.h"
#include "AudioManager.h"
#include "CameraManager.h"

#include "Level.h"
#include "HUD.h"

using namespace Camera;
using namespace UI;

DuckHuntGame::DuckHuntGame() : Game()
{
	background = nullptr;
    music = nullptr;
	floor = nullptr;
    wall1 = nullptr;
    wall2 = nullptr;
	ball = nullptr;
    label = nullptr;
}


void DuckHuntGame::Start()
{
    Super::Start();
    
    //music = M_AUDIO.PlaySample<MusicSample>("Crab_Rave", MP3, seconds(50.0f));
    Level::SpawnActor(MeshActor(RectangleShapeData(Vector2f(window.getSize()), "Background_2", JPG)));

    const Vector2f& _floorSize = Vector2f(window.getSize().x, window.getSize().y * 0.2f);
    floor = Level::SpawnActor(MeshActor(RectangleShapeData(_floorSize, "Floor_2", JPG)));
    floor->SetPosition(Vector2f(0.0f, window.getSize().y - _floorSize.y));

    const Vector2f& _wallSize = Vector2f(window.getSize().x * 0.05f, window.getSize().y * 0.6f - _floorSize.y);

    wall1 = Level::SpawnActor(MeshActor(RectangleShapeData(_wallSize, "Wall", JPG)));
    wall1->SetPosition(Vector2f(0.0f, window.getSize().y * 0.4f));
    wall1->SetTextureRect(IntRect(Vector2i(), Vector2i(663, 663 * 2) / 2));
        
    wall2 = Level::SpawnActor(MeshActor(RectangleShapeData(_wallSize, "Wall", JPG)));
    wall2->SetPosition(Vector2f(window.getSize().x - _wallSize.x, window.getSize().y * 0.4f));
    wall2->SetTextureRect(IntRect(Vector2i(), Vector2i(663, 663 * 2) / 2));

    ball = Level::SpawnActor(Ball(20.0f));
    ball->SetOriginAtMiddle();
    ball->SetPosition(Vector2f(window.getSize().x * 0.5f, window.getSize().y * 0.3f));
    M_CAMERA.GetCurrent()->SetTarget(ball);

    /*
    label = M_HUD.CreateWidget<Label>("Coucou", World);
    label->SetZOrder(1);
    M_HUD.AddToViewport(label);
    ball->AddChild(label, AT_SNAP_TO_TARGET);
    */

    ////TODO check
    //if (MovementComponent* _movement = duck->GetComponent<MovementComponent>())
    //{
    //    _movement->SetTarget(_target);
    //}
}

bool DuckHuntGame::Update()
{
	Super::Update();

    /*
    Shape* _ballShape = ball->GetMesh()->GetShape()->GetDrawable();
    const FloatRect& _ballRect = _ballShape->getGlobalBounds();

    const vector<Shape*>& _shapes =
    {
        floor->GetMesh()->GetShape()->GetDrawable(),
        wall1->GetMesh()->GetShape()->GetDrawable(),
        wall2->GetMesh()->GetShape()->GetDrawable(),
    };

    for (Shape* _shape : _shapes)
    {
        const FloatRect& _shapeRect = _shape->getGlobalBounds();

        if (const optional<FloatRect>& _intersectRect = _ballRect.findIntersection(_shapeRect))
        {
            //const Vector2f& _normal = Vector2f(0.3f, 0.3f);
            const Vector2f& _normal = ComputeNormal(*_intersectRect);
            ball->ApplyBounce(_normal);
        }
    }
    */

    return IsOver();
}

void DuckHuntGame::Stop()
{
	Super::Stop();
}