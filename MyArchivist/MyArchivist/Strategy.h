#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H


class ArchivisationStrategy {
public:
	virtual void startArchivisation() = 0;
	virtual void addFile(const char* filePath) = 0;
	virtual void endArchivisation() = 0;
	~ArchivisationStrategy() = default;
};
class PackingStrategy : public ArchivisationStrategy {
public:
	void startArchivisation() override {};
	void addFile(const char* filePath) override {};
	void endArchivisation() override {};

};

#endif // !STRATEGY_H
