#pragma once
#include <mutex>
namespace st_core
{
	template<class T>
	class CSigleton
	{
	public:
		static T* GetInstance()
		{
			m_Mutex.lock();
			if (NULL == m_pInstance)
			{
				m_pInstance = new T();
			}
			m_Mutex.unlock();
			return m_pInstance;
		}
	protected:
		CSigleton() = default;
		~CSigleton() = default;
	private:
		static T* m_pInstance;
		static std::mutex m_Mutex;
	};
	template<class T> T* CSigleton<T>::m_pInstance = NULL;
	template<class T> std::mutex CSigleton<T>::m_Mutex;
}