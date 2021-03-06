#pragma once
#include <string>
#include <vector>
#include <fnd/MemoryBlob.h>
#include <fnd/List.h>
#include <fnd/ISerialiseableBinary.h>
#include <nx/SacEntry.h>

namespace nx
{
	class SacBinary :
		public fnd::ISerialiseableBinary
	{
	public:
		SacBinary();
		SacBinary(const SacBinary& other);
		SacBinary(const byte_t* bytes, size_t len);

		bool operator==(const SacBinary& other) const;
		bool operator!=(const SacBinary& other) const;
		void operator=(const SacBinary& other);

		// to be used after export
		const byte_t* getBytes() const;
		size_t getSize() const;

		// export/import binary
		void exportBinary();
		void importBinary(const byte_t* bytes, size_t len);

		// variables
		void clear();
		const fnd::List<SacEntry>& getServiceList() const;
		void addService(const SacEntry& service);
	private:
		const std::string kModuleName = "SAC_BINARY";

		// raw binary
		fnd::MemoryBlob mBinaryBlob;

		// variables
		fnd::List<SacEntry> mServices;

		bool isEqual(const SacBinary& other) const;
		void copyFrom(const SacBinary& other);
	};

}
