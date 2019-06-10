#pragma once

#include <mutex>

namespace snp {

	class App {
	public:
		static App* getInstance();

	private:
		App();
		~App();

		App(const App&)				= delete;
		App& operator=(const App&)	= delete;

		static App* instance;
		static std::mutex mtx;
	};
}
