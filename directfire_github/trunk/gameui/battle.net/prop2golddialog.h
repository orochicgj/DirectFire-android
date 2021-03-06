#ifndef _prop2golddialog_h_
#define _prop2golddialog_h_
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

#include "cocos2d.h"
using namespace cocos2d;

#include "uilib/uilib.h"
using namespace uilib;

#include "prop/propdef.h"

#include "gamecore/serverinterface.h"

class Prop2GoldDialog : public BasShowDialog
{
public:
    Prop2GoldDialog(CCNode *parent = 0,const ccColor4B &color = ccc4(0,0,0,0));
    virtual ~Prop2GoldDialog();
    virtual void exec();
    void exchangeReply(bool succ);
protected:
    void finish();
protected:
    void onIncButtonClicked(CCNode *node,void *data);
    void onDecButtonClicked(CCNode *node,void *data);
    void onSubmitButtonClicked(CCNode *node,void *data);
protected:
    void autoIncStep(float dt);
    void autoDecStep(float dt);
    void onIncTouchBegin(CCNode *node,void *data);
    void onIncTouchEnd(CCNode *node,void *data);
    void onDecTouchBegin(CCNode *node,void *data);
    void onDecTouchEnd(CCNode *node,void *data);
protected:
    std::vector<int> m_propExOn;
    std::vector<int> m_propsNum;
    std::vector<CCLabelBMFont*> m_propExLabel;
    std::vector<CCLabelBMFont*> m_propLabel;
    int m_autoStepIndex;
protected:
    ServerInterface *m_serverIface;
    const std::vector<UiMsgEv::PropExchangeRule> *m_propRules;
protected:
    std::string m_id;
    int m_goldHad;
    CCLabelBMFont *m_goldSprite;
    FSizeCCNodeDelegate *m_goldImgDele;
protected:
    VerScrollWidget *m_scrollWidget;
    BasButton *m_confirmButton;
protected:
    bool m_isBusy;
    BasAnimSprite *m_busyAnim;
};
#endif
