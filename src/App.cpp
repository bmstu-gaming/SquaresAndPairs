#include "App.hpp"

namespace snp {

	App* App::instance = nullptr;
	std::mutex App::mtx;

	App* App::getInstance() {
		std::lock_guard<std::mutex> myLock(mtx);
		if (!instance) {
			instance = new App();
		}

		return instance;
	}

	App::App() {
	}

	App::~App() {
	}

}
