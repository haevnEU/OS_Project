#ifndef PARTITIONPAGE_H
#define PARTITIONPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
#include <QGridLayout>

#include "pages_enum.h"
/**
 * @brief The PartitionPage class
 * @details This class is a custom implementation of a wizard page
 *          It request all required information for a partition creation
 * @author Nils Milewski (10010480)
 */
class PartitionPage : public QWizardPage{

    int diskSize;
    /**
     * @brief sbBlockSize Size of the blocks
     * @details This attribtues contians the size of all blocks this partition contains.
     */
    QSpinBox* sbBlockSize;
public:

    /**
     * @brief PartitionPage This is a constructor
     * @details This constructor creates the layout of the page and set required attributes
     * @param parent Parent object which this object is associated with
     */
    PartitionPage(QWidget* parent = nullptr);

    /**
     * @brief nextId This method returns the next id
     * @details This method overrides the default implementation to utilize different intro pages.
     *          It will return the enum of next_page to differenciate between disk and partition pages
     * @return Next id for the wizard
     */
    int nextId() const override;

    /**
     * @brief setVisible This method toggles the visiblity state of the pages
     * @details This method sets the page visible or unset it. It is used to set specific information
     *          The page require to operate based on previous information.
     * @param visible Visibility state of the page
     */
    void setVisible(bool visible) override;

};

#endif // PARTITIONPAGE_H
