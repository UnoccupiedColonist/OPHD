#pragma once

#include "ReportInterface.h"

#include "../ProductListBox.h"
#include "../StructureListBox.h"

#include "../Core/Button.h"
#include "../Core/ComboBox.h"
#include "../Core/UIContainer.h"
#include "../Core/TextArea.h"

#include "../../Things/Structures/Structure.h"

class WarehouseReport : public ReportInterface
{
public:

public:
	WarehouseReport();
	virtual ~WarehouseReport();

	virtual void fillLists() final;
	virtual void clearSelection() final;

	virtual void refresh() final;
	virtual void selectStructure(Structure*) final;

	virtual void update() final;

private:
	void init();
	void _resized(Control*);

	void _fillListFromStructureList(StructureList&);

	void btnShowAllClicked();
	void btnSpaceAvailableClicked();
	void btnFullClicked();
	void btnEmptyClicked();
	void btnDisabledClicked();

	void btnTakeMeThereClicked();

	void fillListSpaceAvailable();
	void fillListFull();
	void fillListEmpty();
	void fillListDisabled();

	void doubleClicked(NAS2D::EventHandler::MouseButton, int, int);

	void lstStructuresSelectionChanged();

	void filterButtonClicked();

	void drawLeftPanel(NAS2D::Renderer&);
	void drawRightPanel(NAS2D::Renderer&);

private:
	Button				btnShowAll;
	Button				btnSpaceAvailable;
	Button				btnFull;
	Button				btnEmpty;
	Button				btnDisabled;

	Button				btnTakeMeThere;

	StructureListBox	lstStructures;
	ProductListBox		lstProducts;
};
