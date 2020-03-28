﻿
// MFC_webnautesDlg.h: 헤더 파일
//

#pragma once
#pragma warning(disable:4996)

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <time.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include "MD_CONFIG.h"
#include "MD_Calendar.h"
#include "pch.h"
#include "framework.h"
#include "MFC_webnautes.h"
#include "MFC_webnautesDlg.h"
#include "afxdialogex.h"
#include <time.h>
#include <iostream>
#include <vector>
#include <Windows.h>
#include "MD_CONFIG.h"
#include "MD_Calendar.h"
#include <atlimage.h>

//(original height / original width) x new width = new height 
#define	THUMBNAIL_WIDTH		90		// thubmail 이미지 크기 640
#define	THUMBNAIL_HEIGHT	67		// thubmail 이미지 크기 480

using namespace cv;

// CMFCwebnautesDlg 대화 상자
class CMFCwebnautesDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCwebnautesDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

												// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_WEBNAUTES_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedPicture();
	CStatic m_picture;
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CSliderCtrl m_sld;
	CEdit m_ed;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	CButton m_list;
	afx_msg void OnBnClickedCancel();
	MD_CONFIG *dlg;
	MD_Calendar *cdlg;
	CListCtrl m_piclist;
	CImageList mImageList;		// 사진 리스트에 같에 사용할 image list
	void SaveDetectImage();										// 사진 저장
	void InsertList(Mat thumb, CString FileName);			// 리스트에 thumbnail 넣기
	void ShowThumbnailList();									// list control 에 사진 thumbnail 보여줌
	void AddThumbnailList(CString FileName, Mat image);	// list control 에 thumbnail 추가
	void removeAllImages();										// mPath 에 저장된 모든 사진 삭제
	UINT nIndex;				// 사진 리스트에 사용되는 list control 과 image list 의 index
	void capPicture(Mat image);
	HBITMAP mat2bmp(cv::Mat* image);
	void Running();
	afx_msg void OnNMDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
};
