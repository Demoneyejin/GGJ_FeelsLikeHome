// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class GGJ_FeelsLikeHomeTarget : TargetRules
{
	public GGJ_FeelsLikeHomeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "GGJ_FeelsLikeHome" } );
	}
}
