/*
 * Anatomy.h
 *
 *  Created on: 07.07.2008
 *      Author: ralph
 */

#ifndef ANATOMY_H_
#define ANATOMY_H_

#include "datasetInfo.h"
#include "surface.h"
#include "../misc/lic/TensorField.h"

class SelectionBox;

class Anatomy : public DatasetInfo , public wxTreeItemData
{

public:
	Anatomy(DatasetHelper* dh);
	Anatomy(DatasetHelper* dh, float* dataset);
	virtual ~Anatomy();

	bool load(wxString filename);
	void draw() {};
	GLuint getGLuint();

	float* getFloatDataset() { return m_floatDataset;};
	float getFloatDataset(int i) {return m_floatDataset[i];};
	TensorField* getTensorField() { return m_tensorField; };
	bool loadNifti(wxString filename);
	void saveNifti(wxString filename);
	void setZero(int x, int y, int z);
	void minimize();
	void dilate();
	void erode();
	SelectionBox* m_roi;

private:
	void generateTexture();
	void generateGeometry() {};
	void initializeBuffer() {};
	void clean() {};
	void smooth() {};
	void activateLIC() {};
	void createOffset(float* dataset);

	double xxgauss(double x, double sigma);
	
	
	void dilate1(std::vector<bool>*, int index);
	void erode1(std::vector<bool>*, int index);

	float *m_floatDataset;
	TensorField* m_tensorField;
};

#endif /* ANATOMY_H_ */