#ifndef SUMMARYPAGE_H
#define SUMMARYPAGE_H

#include <QWizardPage>
#include <QTextEdit>
#include "pages_enum.h"
#include <QGridLayout>

class SummaryPage : public QWizardPage{
public:

    /**
     * @brief PartitionPage This is a constructor
     * @details This constructor creates the layout of the page
     * @param parent Parent object which this object is associated with
     */
    SummaryPage(QWidget* parent = nullptr);

protected:
    /**
     * @brief initializePage This method initializes the page
     * @details This method overrides the base initializePage method to ensure that
     *          Custom behaivour can be implemented. This method sets the subtitle with all previous entered information
     */
    void initializePage() override;
};

#endif // SUMMARYPAGE_H
