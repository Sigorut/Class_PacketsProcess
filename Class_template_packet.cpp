#include "Class_template_packet.h"

using namespace std;
struct Packet {
	Packet(unsigned char* data, unsigned int dataCount, unsigned int packetId) :
		dataCount{ dataCount }, packetId{ packetId }
	{
		this->data = new unsigned char[dataCount+1];
		for (int i = 0; i < (int)dataCount; i++) {
			this->data[i] = data[i];
		}
		this->data[dataCount] = '\0';
		allSizePackets += dataCount;
	}
	~Packet() {
		delete[] data;
	}
	unsigned char* data;
	unsigned int dataCount;
	unsigned int packetId;
	static int allSizePackets;
};
int Packet::allSizePackets = 0;


template<typename Tp>
class PacketsProcess {
public:
	PacketsProcess(Tp maxLenOnePacket, Tp maxPackets, Tp maxSizePakets) :
		maxLenOnePacket{ maxLenOnePacket }, maxPackets{ maxPackets }, maxSizePakets{ maxSizePakets }
	{}
	bool Push(unsigned char* data, unsigned int dataCount, unsigned int packetId)
	{
		if (dataCount > maxLenOnePacket && allPackets.size() == maxPackets &&
			dataCount + Packet::allSizePackets > maxSizePakets) {
			return false;
		}
		allPackets.push(Packet(data, dataCount, packetId));
		return true;
	}
	bool Pop(unsigned char* buffer, unsigned int bufferSize, unsigned int& dataCount, unsigned int& packetId)
	{
		if (allPackets.size() == 0) {
			return false;
		}
		Packet::allSizePackets -= allPackets.front().dataCount;
		Equating(buffer, bufferSize, dataCount, packetId);
		allPackets.pop();
		return true;
	}
private:
	Tp maxLenOnePacket;
	Tp maxPackets;
	Tp maxSizePakets;
	queue<Packet> allPackets;
	void Equating(unsigned char* buffer, unsigned int bufferSize, unsigned int& dataCount, unsigned int& packetId) {
		for (int i = 0; i < (int)allPackets.front().dataCount; i++) {
			if (i == bufferSize) {
				dataCount = i + 1;
				break;
			}
			allPackets.front().data[i] = buffer[i];
		}
		packetId = allPackets.front().packetId;
	}
};

int main()
{
	//PacketsProcess test{ 2,2,4 };
	//unsigned char myString[] = "hhh";
	//unsigned char* tmpBuffer = &myString[0];
	//unsigned char buf[256];
	//unsigned int datac = 0;
	//unsigned int id = 0;
	//test.Push(tmpBuffer, 3, 123);
	//test.Push(tmpBuffer, 2, 2145);
	//test.Pop(buf, 3, datac, id);
	return 0;
}
