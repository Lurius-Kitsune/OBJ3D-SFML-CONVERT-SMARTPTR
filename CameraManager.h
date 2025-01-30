#pragma once
#include "Singleton.h"
#include "CameraActor.h"
#include "Level.h"
#include "RenderType.h"

namespace Camera
{
	struct RenderData
	{
		RenderType type;
		using RenderCallback = function<void(RenderWindow&)>;
		RenderCallback callback;
		int zOrder;

		RenderData(const RenderCallback& _callback, const RenderType& _type = World)
		{
			callback = _callback;
			type = _type;
			zOrder = 0;
		}
	};

	class CameraManager : public Singleton<CameraManager>
	{
		multimap<int, u_int> allElements;
		map<u_int, RenderData> allRendersData;
		map<string, Shared<CameraActor>> allCameras;
		Shared<CameraActor> current;

	public:
		FORCEINLINE u_int BindOnRenderWindow(RenderData _data, const int _zOrder = 0)
		{
			const u_int& _id = GetUniqueID();
			_data.zOrder = _zOrder;
			allRendersData.insert({ _id, _data });
			allElements.insert({ _zOrder, _id });
			return _id;
		}
		FORCEINLINE void SetCurrent(CameraActor* _camera)
		{
			if (!_camera) return;
			current = Shared<CameraActor>(_camera);
		}
		FORCEINLINE Shared<CameraActor> GetCurrent() const
		{
			return current;
		}
		FORCEINLINE Shared<CameraActor> GetCameraByName(const string& _name) const
		{
			if (!allCameras.contains(_name)) return nullptr;
			return allCameras.at(_name);
		}
	private:
		FORCEINLINE void Register(CameraActor* _camera)
		{
			if (!_camera) return;

			allCameras.insert({ _camera->GetName(), Shared<CameraActor>(_camera) });
			//allCameras.insert({ _camera->GetDisplayName(), _camera });
		}

	public:
		CameraManager();

		void RenderAllCameras(RenderWindow& _window);
		void UnbindOnRenderWindow(const u_int& _uniqueId);

		template <typename Type = CameraActor, typename ...Args, IS_BASE_OF(CameraActor, Type)>
		Shared<Type> CreateCamera(Args... _args)
		{
			Shared<Type> _camera = Level::SpawnActor<Type>(Type(_args...));
			Register(_camera.get());

			if (!current)
			{
				SetCurrent(_camera.get());
			}

			return _camera;
		}
	};
}